#include "pch.h"
#include "harness.h"


int day4(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}

int day4_2(const stringlist& input)
{
    for (auto& line : input)
    {
        (void)line;
    }

    return -1;
}


void run_day4()
{
    string sample =
R"(beep
boop
blarp)";

    test(-100, day4(READ(sample)));
    //gogogo(day4(LOAD(4)));

    //test(-100, day4_2(READ(sample)));
    //gogogo(day4_2(LOAD(4)));
}