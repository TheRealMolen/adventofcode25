#include "pch.h"
#include "harness.h"


int day3(const stringlist& input)
{
    int total = 0;

    for (auto& line : input)
    {
        int maxJoltage = 0;

        const auto lineEnd = end(line);
        for (auto itA = begin(line); (itA+1) != lineEnd; ++itA)
        {
            const int jA = (*itA - '0') * 10;
            for (auto itB = itA + 1; itB != lineEnd; ++itB)
            {
                const int jB = (*itB - '0');

                if (jA + jB > maxJoltage)
                {
                    maxJoltage = jA + jB;
                }
            }
        }

        total += maxJoltage;
    }

    return total;
}

i64 day3_2(const stringlist& input)
{
    constexpr int NumBatteries = 12;

    i64 total = 0;
    for (auto& line : input)
    {
        vector<i8> bats;
        bats.reserve(line.size());
        ranges::transform(line, back_inserter(bats), [](char c) { return c - '0'; });
        
        i64 running = 0;
        auto itBatBegin = begin(bats);
        auto itBatEnd = end(bats) - (NumBatteries - 1);
        for (int bat = 0; bat < NumBatteries; ++bat)
        {
            auto itBiggest = max_element(itBatBegin, itBatEnd);
            running = 10 * running + *itBiggest;
            itBatBegin = itBiggest + 1;
            ++itBatEnd;
        }

        total += running;
    }

    return total;
}


void run_day3()
{
    string sample =
R"(987654321111111
811111111111119
234234234234278
818181911112111)";

    test(357, day3(READ(sample)));
    gogogo(day3(LOAD(3)));

    test(3121910778619ll, day3_2(READ(sample)));
    gogogo(day3_2(LOAD(3)));
}
