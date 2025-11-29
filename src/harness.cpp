#include "pch.h"

#include "harness.h"


using namespace std;


vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;

    auto delim_len = delim.length();
    size_t offset = 0;
    for (;;)
    {
        auto delim_pos = str.find(delim, offset);
        auto len = delim_pos == string::npos ? string::npos : delim_pos - offset;

        string token = str.substr(offset, len);
        tokens.push_back(token);

        if (delim_pos == string::npos)
            break;
        offset = delim_pos + delim_len;
    };

    return tokens;
}



// -------------------------------------------------------------------


int gday = 1;
int gpart = 1;
int gtest = 1;


void skip( const char* message )
{
    cout << "day" << gday << ",p" << gpart << YELLOW << " skipped " << GREY << " (" << message << ")" << RESET << endl;

    if (gpart == 2)
    {
        gday++;
        gpart = 1;
        cout << "\n" << GARLAND(4) << "\n" << endl;
    }
    else
        gpart++;

    gtest = 1;
}


void jumptoday(int day)
{
    cout << YELLOW << "SKIPPING" << RESET << " to day " << day << YELLOW << "/\\/\\/\\/\\/\\/\\/\\/\\/\n" << RESET << endl;
    cout << "\n" << GARLAND(4) << "\n" << endl;
    gday = day;
    gpart = 1;
    gtest = 1;
}

