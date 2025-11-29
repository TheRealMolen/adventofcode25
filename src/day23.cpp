#include "pch.h"
#include "harness.h"


int day23(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}

int day23_2(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}


void run_day23()
{
    string sample =
R"(beep
boop
blarp)";

    test(-100, day23(READ(sample)));
    //gogogo(day23(LOAD(23)));

    //test(-100, day23_2(READ(sample)));
    //gogogo(day23_2(LOAD(23)));
}