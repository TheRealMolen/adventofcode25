#include "pch.h"
#include "harness.h"

pair<i64,bool> get_half_p10(i64 x)
{
    if (x < 10)
        return {10, false};
    if (x < 100)
        return {10, true};
    if (x < 1000)
        return {100, false};
    if (x < 10'000)
        return {100, true};
    if (x < 100'000)
        return {1000, false};
    if (x < 1'000'000)
        return {1000, true};
    if (x < 10'000'000)
        return {10'000, false};
    if (x < 100'000'000)
        return {10'000, true};
    if (x < 1'000'000'000)
        return {100'000, false};
    if (x < 10'000'000'000)
        return {100'000, true};

    throw format("int too big: {}", x);
}

const vector<pair<i64,i64>> p10_multiples[] =
{
    {},
    { {11, 9} },
    { {111, 9} },
    { {101, 99}, {1111, 9}, },
    { {11111, 9} },
    { {1001, 999}, {10101, 99}, {111111, 9}, },
    { {1111111, 9} },
    { {10001, 9999}, {1010101, 99}, {11111111, 9}, },
    { {1001001, 999}, {111111111, 9}, },
    { {100001, 99999}, {101'010'101, 99}, {1'111'111'111, 9}, },
    { {11'111'111'111, 9}, },
};

const vector<pair<i64,i64>>& get_p10_multiples(i64 x)
{
    if (x <= 9)
        return p10_multiples[0];
    if (x <= 99)
        return p10_multiples[1];
    if (x <= 999)
        return p10_multiples[2];
    if (x <= 9999)
        return p10_multiples[3];
    if (x <= 99'999)
        return p10_multiples[4];
    if (x <= 999'999)
        return p10_multiples[5];
    if (x <= 9'999'999)
        return p10_multiples[6];
    if (x <= 99'999'999)
        return p10_multiples[7];
    if (x <= 999'999'999)
        return p10_multiples[8];
    if (x <= 9'999'999'999)
        return p10_multiples[9];

    throw format("int too big: {}", x);
}

i64 day2(const string& input)
{
    i64 result = 0;

    for (const string& range : split(input, ","s))
    {
        i64 from=-1;
        i64 to=-1;
        sscanf(range.c_str(), "%ld-%ld", &from, &to);

        auto [from10,fromValid] = get_half_p10(from);
        auto [to10,toValid] = get_half_p10(to);

        if (from10 == to10 && !fromValid && !toValid)
            continue;

        if (!fromValid)
        {
            from = (from10 * from10) / 10;
            //cout << "adjusting range " << range << " to be " << from << "-" << to << "\th10=" << from10 << endl;
        }
        if (!toValid)
        {
            to10 /= 10;
            to = (to10 * to10) - 1;
            //cout << "adjusting range " << range << " to be " << from << "-" << to << "\th10=" << from10 << endl;
        }

        if (from10 != to10)
            throw format("too much range in '{}'", range);

        i64 hi = from / from10;
        i64 lo = from % from10;

        if (lo < hi)
            lo = hi;
        else if (hi < lo)
        {
            ++hi;
            lo = hi;
        }
        
        i64 hiShift = hi * from10;
        //if (hiShift + lo <= to)
        //    cout << "range " << from << "-" << to << " starting counting from " << hi << lo << endl;
        
        while (hiShift + lo <= to)
        {
        //    cout << "   .. found one: " << hi << lo << endl;
            result += hiShift + lo;

            ++hi;
            ++lo;
            hiShift += from10;
        }
    }

    return result;
}

i64 day2_2(const string& input)
{
    i64 result = 0;

    vector<i64> found;

    for (const string& range : split(input, ","s))
    {
        i64 rngFrom=-1;
        i64 rngTo=-1;
        sscanf(range.c_str(), "%ld-%ld", &rngFrom, &rngTo);

        auto& fromMults = get_p10_multiples(rngFrom);
        auto& toMults = get_p10_multiples(rngTo);

        vector<pair<i64,i64>> mults;
        set_union(
            begin(fromMults), end(fromMults),
            begin(toMults), end(toMults),
            back_inserter(mults));

        cout << "checking " << range << " - " << size(mults) << " patterns" << endl;
        for (auto [mult, maxChunk] : mults)
        {
          //  cout << "range " << range << " need to check mult " << mult << " / " << maxChunk << endl;

            i64 from = rngFrom;
            i64 to = rngTo;

            if (from < mult)
            {
                from = mult;
                if (from > to)
                    continue;

//                cout << "  * adjusting range " << range << " to be " << from << "-" << to << endl;
            }
            if (to > (mult * maxChunk))
            {
                to = mult * maxChunk;
                if (from > to)
                    continue;

//                cout << "  * adjusting range " << range << " to be " << from << "-" << to << endl;
            }

            // THINKS: this often drastically underestimates; could do with a better start guess
            i64 chunk = (from + maxChunk) / mult;
        //    cout << "  > initial chunk " << chunk << endl;

            i64 id = chunk * mult;
            while (id < from)
                id += mult;
            while (id <= to)
            {
                if (find(begin(found), end(found), id) == end(found))
                {
                    cout << "   .. found one: " << id << endl;
                    result += id;
                    found.push_back(id);
                }
    //            else
    //            {
    //                cout << "        (ignoring dupe " << id << ")" << endl;
    //            }
                
                id += mult;
            }
        }
    }

    return result;
}


void run_day2()
{
    string sample = "11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124";

    test(1227775554LL, day2(sample));
    gogogo(day2(LOADSTR(2)));

    test(4174379265, day2_2(sample));
    gogogo(day2_2(LOADSTR(2)));
    // 69555472140 too high
}
