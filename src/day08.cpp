#include "pch.h"
#include "harness.h"


int day8(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}

int day8_2(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}


void run_day8()
{
    string sample =
R"(beep
boop
blarp)";

    test(-100, day8(READ(sample)));
    //gogogo(day8(LOAD(8)));

    //test(-100, day8_2(READ(sample)));
    //gogogo(day8_2(LOAD(8)));
}