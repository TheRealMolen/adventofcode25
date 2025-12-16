#include "pch.h"
#include "harness.h"


i64 day6(const stringlist& input)
{
    vector<vector<i64>> values;
    for (auto& line : input | views::take(size(input) - 1))
    {
        values.emplace_back(string_to_intlist<i64>(line));
    }

    i64 total = 0;
    u64 valueIx = 0;
    for (const char c : input.back())
    {
        if (c == ' ')
            continue;

        if (c == '*')
        {
            i64 prod = 1;
            for (const auto& row : values)
                prod *= row[valueIx];

            total += prod;
        }
        else if (c == '+')
        {
            i64 sum = 0;
            for (const auto& row : values)
                sum += row[valueIx];

            total += sum;
        }

        ++valueIx;
    }

    return total;
}

i64 day6_2(const stringlist& input)
{
    auto inputNums = input | views::take(size(input)-1);
    const string& inputOps = input.back();

    i64 total = 0;
    
    vector<i64> nums;
    string num;
    for (i64 col = isize(input.front()) - 1; col >= 0; --col)
    {
        num.clear();

        for (const auto& row : inputNums)
            num += row[col];

        nums.push_back(stol(num));

        const char op = inputOps[col];
        if (op == ' ')
            continue;

        if (op == '*')
            total += reduce(begin(nums), end(nums), i64(1), multiplies<i64>());
        else if (op == '+')
            total += reduce(begin(nums), end(nums), i64(0), plus<i64>());

        nums.clear();
        --col;  // skip the blank column
    }
    
    return total;
}


void run_day6()
{
    string sample =
R"(123 328  51 64 
 45 64  387 23 
  6 98  215 314
*   +   *   +  )";

    test(4277556l, day6(READ(sample)));
    gogogo(day6(LOAD(6)));

    test(3263827, day6_2(READ(sample)));
    gogogo(day6_2(LOAD(6)));
}
