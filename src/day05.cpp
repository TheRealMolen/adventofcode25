#include "pch.h"
#include "harness.h"


int day5(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}

int day5_2(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}


void run_day5()
{
    string sample =
R"(beep
boop
blarp)";

    test(-100, day5(READ(sample)));
    //gogogo(day5(LOAD(5)));

    //test(-100, day5_2(READ(sample)));
    //gogogo(day5_2(LOAD(5)));
}