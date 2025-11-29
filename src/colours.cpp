#include "colours.h"

#ifdef _WIN32

#include <conio.h>
#include <Windows.h>
#include <wincon.h>

HANDLE hStdIn;
HANDLE hStdOut;

void initcolours()
{
    hStdIn = GetStdHandle(STD_INPUT_HANDLE);
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

#else

const char* DARK_RED    = "\033[31m";
const char* RED         = "\033[91m";
const char* DARK_BLUE   = "\033[34m";
const char* BLUE        = "\033[94m";
const char* DARK_GREEN  = "\033[32m";
const char* GREEN       = "\033[92m";
const char* YELLOW      = "\033[93m";
const char* GOLD        = "\033[33m";
const char* CYAN        = "\033[96m";
const char* DARK_CYAN   = "\033[36m";
const char* DARK_PURPLE = "\033[35m";
const char* PURPLE      = "\033[95m";
const char* GREY        = "\033[37m";
const char* WHITE       = "\033[97m";
const char* BLACK       = "\033[30m";
const char* RESET       = "\033[0m";


void initcolours()
{
}

#endif



// ---- T W I N K L E S ----

#ifdef _WIN32

const WORD kwhite = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const WORD kgrey = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
const wchar_t* ktwinkles = L"-+x┼x+- ";
const WORD ktwincols[] = { kgrey, kwhite, kgrey, kwhite, kwhite, kgrey, kgrey, kgrey };
COORD zerozero = { 0, 0 };
COORD oneXone = { 1, 1 };

struct Sparkle
{
    COORD pos;
    int t;

    Sparkle(COORD p) : pos(p), t(-1) {/**/ }

    bool tick()
    {
        t += 1;
        if (!ktwinkles[t]) return false;

        CHAR_INFO c;
        c.Char.UnicodeChar = ktwinkles[t];
        c.Attributes = ktwincols[t];
        SMALL_RECT rect = { pos.X, pos.Y, 3000, 3000 };
        WriteConsoleOutput(hStdOut, &c, oneXone, zerozero, &rect);

        return true;
    }
};

int twinkleforever()
{
    cout << "                          " << GARLAND(5) << "  press a key  " << GARLAND(5) << endl;

    // step 1. read back current screen
    CONSOLE_SCREEN_BUFFER_INFOEX screeninfo;
    screeninfo.cbSize = sizeof(screeninfo);
    if (!GetConsoleScreenBufferInfoEx(hStdOut, &screeninfo))
    {
        cerr << "FAILED to read console info: " << GetLastError() << endl;
        return 1;
    }
    size_t bufsize = screeninfo.dwSize.X * screeninfo.dwSize.Y;
    CHAR_INFO *pscreenbuf = new CHAR_INFO[bufsize];
    SMALL_RECT readregion = screeninfo.srWindow;
    if (!ReadConsoleOutput(hStdOut, pscreenbuf, screeninfo.dwSize, zerozero, &readregion))
    {
        cerr << "FAILED to read from console: " << GetLastError() << endl;
        return 1;
    }

    // step 2: make a big ol' list of all the coords that are free
    vector<COORD> free;
    //int wndwidth = screeninfo.srWindow.Right - screeninfo.srWindow.Left;
    //int wndheight = screeninfo.srWindow.Bottom - screeninfo.srWindow.Top;
    size_t i = 0;
    COORD pos = { screeninfo.srWindow.Left,screeninfo.srWindow.Top };
    for (; pos.Y < screeninfo.srWindow.Bottom; ++pos.Y)
    {
        i = (pos.Y- screeninfo.srWindow.Top) * screeninfo.dwSize.X;
        for (pos.X = screeninfo.srWindow.Left; pos.X < screeninfo.srWindow.Right; ++pos.X, ++i)
        {
            if (pscreenbuf[i].Char.UnicodeChar == L' ')
            {
                free.push_back(pos);
            }
        }
    }

    deque<Sparkle> sparkles;
    uint32_t frame = 0;
    for (;; ++frame)
    {
        // add a new sparkle
        size_t ipos = rand() % free.size();
        Sparkle newsparkle(free[ipos]);
        sparkles.push_back(newsparkle);

        // tick all the sparkles
        for (auto it = sparkles.begin(); it != sparkles.end();)
        {
            if (!it->tick())
                it = sparkles.erase(it);
            else
                ++it;
        }

        if (_kbhit())
            break;

        Sleep(150);
    }

    return 0;
}

#endif


