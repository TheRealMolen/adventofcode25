#include "pch.h"
#include "harness.h"


int day3(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}

int day3_2(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}


void run_day3()
{
    string sample =
R"(beep
boop
blarp)";

    test(-100, day3(READ(sample)));
    //gogogo(day3(LOAD(3)));

    //test(-100, day3_2(READ(sample)));
    //gogogo(day3_2(LOAD(3)));
}