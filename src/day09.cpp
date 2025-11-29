#include "pch.h"
#include "harness.h"


int day9(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}

int day9_2(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}


void run_day9()
{
    string sample =
R"(beep
boop
blarp)";

    test(-100, day9(READ(sample)));
    //gogogo(day9(LOAD(9)));

    //test(-100, day9_2(READ(sample)));
    //gogogo(day9_2(LOAD(9)));
}