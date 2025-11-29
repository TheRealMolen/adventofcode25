#include "pch.h"
#include "harness.h"


int day6(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}

int day6_2(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}


void run_day6()
{
    string sample =
R"(beep
boop
blarp)";

    test(-100, day6(READ(sample)));
    //gogogo(day6(LOAD(6)));

    //test(-100, day6_2(READ(sample)));
    //gogogo(day6_2(LOAD(6)));
}