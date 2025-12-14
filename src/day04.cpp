#include "pch.h"
#include "harness.h"


int day4(const stringlist& input)
{
    const u64 ogWidth = input.front().size();
    const u64 ogHeight = input.size();
    const u64 width = ogWidth + 2;
    const u64 height = ogHeight + 2;

    vector<char> grid(width * height, '.');
    auto itDest = begin(grid) + width + 1;
    for (auto& line : input)
    {
        copy(begin(line), end(line), itDest);
        itDest += width;
    }

    int total = 0;

    auto itCell = begin(grid) + width;
    for (u64 y = 0; y < ogHeight; ++y)
    {
        ++itCell;

        for (u64 x = 0; x < ogWidth; ++x, ++itCell)
        {
            if (*itCell != '@')
                continue;

            int surrounding = count(itCell - (width + 1), itCell - (width - 2), '@');
            surrounding += count(itCell - 1, itCell + 2, '@');
            surrounding += count(itCell + (width - 1), itCell + (width + 2), '@');

            if (surrounding < 5)    // nb 5 because we'll count the roll itself
            {
                ++total;
            }
        }

        ++itCell;
    }

    return total;
}

int day4_2(const stringlist& input)
{
    const u64 ogWidth = input.front().size();
    const u64 ogHeight = input.size();
    const u64 width = ogWidth + 2;
    const u64 height = ogHeight + 2;

    vector<char> grid(width * height, '.');
    auto itDest = begin(grid) + width + 1;
    for (auto& line : input)
    {
        copy(begin(line), end(line), itDest);
        itDest += width;
    }

    int total = 0;

    for (;;)
    {
        vector<decltype(grid)::iterator> toRemove;

        auto itCell = begin(grid) + width;
        for (u64 y = 0; y < ogHeight; ++y)
        {
            ++itCell;

            for (u64 x = 0; x < ogWidth; ++x, ++itCell)
            {
                if (*itCell != '@')
                    continue;

                int surrounding = count(itCell - (width + 1), itCell - (width - 2), '@');
                surrounding += count(itCell - 1, itCell + 2, '@');
                surrounding += count(itCell + (width - 1), itCell + (width + 2), '@');

                if (surrounding < 5)    // nb 5 because we'll count the roll itself
                {
                    toRemove.push_back(itCell);
                }
            }

            ++itCell;
        }

        if (toRemove.empty())
            break;

        total += isize(toRemove);
        for (auto itMoved : toRemove)
            *itMoved = 'x';
    }

    return total;
}


void run_day4()
{
    string sample =
R"(..@@.@@@@.
@@@.@.@.@@
@@@@@.@.@@
@.@@@@..@.
@@.@@@@.@@
.@@@@@@@.@
.@.@.@.@@@
@.@@@.@@@@
.@@@@@@@@.
@.@.@@@.@.)";

    test(13, day4(READ(sample)));
    gogogo(day4(LOAD(4)));

    test(43, day4_2(READ(sample)));
    gogogo(day4_2(LOAD(4)));
}

