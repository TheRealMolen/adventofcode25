#include "pch.h"
#include "harness.h"


int day25(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}

int day25_2(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}


void run_day25()
{
    string sample =
R"(beep
boop
blarp)";

    test(-100, day25(READ(sample)));
    //gogogo(day25(LOAD(25)));

    //test(-100, day25_2(READ(sample)));
    //gogogo(day25_2(LOAD(25)));
}