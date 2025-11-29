#include "pch.h"
#include "harness.h"


int day12(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}

int day12_2(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}


void run_day12()
{
    string sample =
R"(beep
boop
blarp)";

    test(-100, day12(READ(sample)));
    //gogogo(day12(LOAD(12)));

    //test(-100, day12_2(READ(sample)));
    //gogogo(day12_2(LOAD(12)));
}