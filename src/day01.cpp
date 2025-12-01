#include "pch.h"
#include "harness.h"

int day1(const stringlist& input)
{
    int numZeroes = 0;
    int currNum = 50;
    for (auto& line : input)
    {
        char dir = line[0];
        int delta = strtol(line.data() + 1, nullptr, 10);
        if (dir == 'L')
            delta = 100 - delta;
        currNum = (currNum + delta) % 100;

        if (currNum == 0)
            ++numZeroes;
    }

    return numZeroes;
}

int day1_2_broken(const stringlist& input)
{
    int numZeroes = 0;
    int currNum = 50;
    for (auto& line : input)
    {
        char dir = line[0];
        int delta = strtol(line.data() + 1, nullptr, 10);
        if (dir == 'L')
        {
            delta = -delta;
            if (currNum == 0)
                currNum += 100;
        }
        currNum = (currNum + delta);

        while (currNum > 99)
        {
            currNum -= 100;
            if (currNum)
                ++numZeroes;
        }
        while (currNum < 0)
        {
            currNum += 100;
            if (currNum)
                ++numZeroes;
        }

        if (currNum == 0)
            ++numZeroes;
    }

    return numZeroes;
}

int day1_2(const stringlist& input)
{
    int numZeroes = 0;
    int currNum = 50;
    for (auto& line : input)
    {
        char dir = line[0];
        int delta = strtol(line.data() + 1, nullptr, 10);

        if (dir == 'L')
        {
            for (; delta; --delta)
            {
                --currNum;
                if (currNum == 0)
                    ++numZeroes;
                if (currNum < 0)
                    currNum += 100;
            }
        }
        else
        {
            for (; delta; --delta)
            {
                ++currNum;
                if (currNum > 99)
                    currNum -= 100;
                if (currNum == 0)
                    ++numZeroes;
            }
        }
    }

    return numZeroes;
}


void run_day1()
{
    string sample =
R"(L68
L30
R48
L5
R60
L55
L1
L99
R14
L82)";

    test(3, day1(READ(sample)));
    gogogo(day1(LOAD(1)));

    test(6, day1_2(READ(sample)));
    gogogo(day1_2(LOAD(1)));
    // 6452 too low
}
