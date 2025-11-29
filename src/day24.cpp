#include "pch.h"
#include "harness.h"


int day24(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}

int day24_2(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}


void run_day24()
{
    string sample =
R"(beep
boop
blarp)";

    test(-100, day24(READ(sample)));
    //gogogo(day24(LOAD(24)));

    //test(-100, day24_2(READ(sample)));
    //gogogo(day24_2(LOAD(24)));
}