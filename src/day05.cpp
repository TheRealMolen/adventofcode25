#include "pch.h"
#include "harness.h"

int day5(const stringlist& input)
{
    vector<pair<u64,u64>> freshRanges;
    auto itLine = begin(input);
    for (; !itLine->empty(); ++itLine)
    {
        u64 lo, hi;
        sscanf(itLine->c_str(), "%lu-%lu", &lo, &hi);
        freshRanges.emplace_back(lo, hi);
    }

    int numFresh = 0;
    for (; itLine != end(input); ++itLine)
    {
        u64 id = std::strtoul(itLine->c_str(), nullptr, 10);
        
        for (const auto& [lo,hi] : freshRanges)
        {
            if (id < lo || id > hi)
                continue;

            ++numFresh;
            break;
        }
    }

    return numFresh;
}

i64 day5_2(const stringlist& input)
{
    vector<pair<i64,i64>> freshRanges;
    auto itLine = begin(input);
    for (; !itLine->empty(); ++itLine)
    {
        i64 lo, hi;
        sscanf(itLine->c_str(), "%ld-%ldu", &lo, &hi);

        pair<i64,i64> range { lo, hi };
        auto itLowerBnd = lower_bound(begin(freshRanges), end(freshRanges), range,
            [](auto& existing, auto& needle) { return existing.second < needle.first; });

        // possible cases:
        // 1. this is a new, disjunct range
        // 2. this range covers one or more existing ranges
        //
        // for #2, we 
        //  - make the lowest-starting range encapsulate the whole lot
        //  - set any other intersecting range to have lo>hi
        //  - then go through and remove all invalid ranges before moving on to next range

        if (itLowerBnd == end(freshRanges))
        {
            freshRanges.emplace_back(lo, hi);
            continue;
        }
        if (itLowerBnd->first > hi)
        {
            freshRanges.emplace(itLowerBnd, lo, hi);
            continue;
        }

        itLowerBnd->first = min(lo, itLowerBnd->first);
        itLowerBnd->second = max(hi, itLowerBnd->second);

        // now merge with and invalidate any overlapped ranges following itLowerBnd
        for (auto it = itLowerBnd+1; it != end(freshRanges); ++it)
        {
            if (it->first > hi)
                break;

            itLowerBnd->second = max(itLowerBnd->second, it->second);
            it->second = it->first - 1;
        }
        freshRanges.erase(remove_if(begin(freshRanges), end(freshRanges), [](const auto& r)
                { return r.second < r.first; })
            , end(freshRanges));
    }

    i64 totalFresh = transform_reduce(begin(freshRanges), end(freshRanges), i64(0), plus<i64>(),
        [](auto& range) -> i64 { return range.second - range.first + 1; });

    return totalFresh;
}


void run_day5()
{
    string sample =
R"(3-5
10-14
16-20
12-18

1
5
8
11
17
32)";

    test(3, day5(READ(sample)));
    gogogo(day5(LOAD(5)));

    test(14, day5_2(READ(sample)));
    gogogo(day5_2(LOAD(5)));
}
