#pragma once

#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#include <wincon.h>
#endif

using std::ostream;


void initcolours();

#ifdef _WIN32
extern HANDLE hStdIn;
extern HANDLE hStdOut;

inline ostream& COLOUR(ostream& _Ostr, WORD code)
{
    _Ostr.flush();
    SetConsoleTextAttribute(hStdOut, code);
    return (_Ostr);
}
inline ostream& DARK_RED(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_RED); }
inline ostream& RED(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_RED | FOREGROUND_INTENSITY); }
inline ostream& DARK_BLUE(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_BLUE); }
inline ostream& BLUE(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_BLUE | FOREGROUND_INTENSITY); }
inline ostream& DARK_GREEN(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_GREEN); }
inline ostream& GREEN(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_GREEN | FOREGROUND_INTENSITY); }
inline ostream& YELLOW(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); }
inline ostream& GOLD(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_RED | FOREGROUND_GREEN); }
inline ostream& CYAN(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); }
inline ostream& DARK_CYAN(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_BLUE | FOREGROUND_GREEN); }
inline ostream& DARK_PURPLE(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_BLUE | FOREGROUND_RED); }
inline ostream& PURPLE(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); }
inline ostream& GREY(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); }
inline ostream& WHITE(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); }
inline ostream& BLACK(ostream& _Ostr) { return COLOUR(_Ostr, 0); }
inline ostream& RESET(ostream& _Ostr) { return COLOUR(_Ostr, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); }

#else

extern const char* DARK_RED;
extern const char* RED;
extern const char* DARK_BLUE;
extern const char* BLUE;
extern const char* DARK_GREEN;
extern const char* GREEN;
extern const char* YELLOW;
extern const char* GOLD;
extern const char* CYAN;
extern const char* DARK_CYAN;
extern const char* DARK_PURPLE;
extern const char* PURPLE;
extern const char* GREY;
extern const char* WHITE;
extern const char* BLACK;
extern const char* RESET;

#endif


// ------ GARLAND! ----------------
struct Garland
{
    int length;
    Garland(int _length) : length(_length) {/**/ }
};
inline Garland GARLAND(int length)
{
    return Garland(length);
}
inline ostream& operator<<(ostream& os, const Garland& g)
{
    os << YELLOW << "**";
    for (int i = 0; i < g.length; ++i)
    {
        os << RED << "o" << YELLOW << "*" << GREEN << "o" << YELLOW << "*";
    }
    os << "*" << RESET;
    return os;
}


#ifdef _WIN32

int twinkleforever();

#endif


