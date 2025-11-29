#include "pch.h"
#include "harness.h"


int day10(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}

int day10_2(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}


void run_day10()
{
    string sample =
R"(beep
boop
blarp)";

    test(-100, day10(READ(sample)));
    //gogogo(day10(LOAD(10)));

    //test(-100, day10_2(READ(sample)));
    //gogogo(day10_2(LOAD(10)));
}