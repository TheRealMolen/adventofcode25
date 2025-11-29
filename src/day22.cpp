#include "pch.h"
#include "harness.h"


int day22(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}

int day22_2(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}


void run_day22()
{
    string sample =
R"(beep
boop
blarp)";

    test(-100, day22(READ(sample)));
    //gogogo(day22(LOAD(22)));

    //test(-100, day22_2(READ(sample)));
    //gogogo(day22_2(LOAD(22)));
}