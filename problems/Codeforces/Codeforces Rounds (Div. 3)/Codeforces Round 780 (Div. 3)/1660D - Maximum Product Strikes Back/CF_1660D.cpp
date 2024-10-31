/**
 * Title: "Maximum Product Strikes Back", Codeforces problem. 
 * Date: Tuesday, 26 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second

typedef pair<int, int>          PII;
typedef vector<int>             VI;


struct Count {
    int twos, ones, negative;

    Count() : twos(0), ones(0), negative(0) {}
    Count(int twos,int ones, int negative) : twos(twos), ones(ones), negative(negative) {}
    
    Count operator +(const int &num) {
        twos += (abs(num) == 2);
        ones += (abs(num) == 1);
        negative += (num < 0);

        return *this;
    }

    Count operator -(const int &num) {
        twos -= (abs(num) == 2);
        ones -= (abs(num) == 1);
        negative -= (num < 0);

        return *this;
    }

    Count c_abs() const {
        return Count(twos, ones, 0);
    }

    bool operator >(const Count &count) const {
        if(negative % 2 == 0 && count.negative % 2 == 0)
            return twos > count.twos;
        if(negative % 2 != 0 && count.negative % 2 != 0)
            return twos < count.twos;
        return (negative % 2 == 0 && count.negative % 2 != 0);
    }

    bool operator >=(const Count &count) const {
        return !(count > *this);
    }
};


void removeNeg(const VI &numbers, PII range, Count value, Count &maxCount, PII &best)
{
    int left = range.FF, right = range.SS;
    Count maxLeft = value, maxRight = value;

    while(left < right) {
        if(numbers[left] > 0)
            maxLeft = maxLeft - numbers[left], left++;

        if(numbers[right] > 0)
            maxRight = maxRight - numbers[right], right--;
        
        if(numbers[right] < 0 && numbers[left] < 0) {
            maxLeft = maxLeft - numbers[left], maxRight = maxRight - numbers[right];
            PII temp = best;
            Count count = Count();

            if(maxLeft > value && maxLeft >= maxRight && maxLeft.negative % 2 == 0)
                count = maxLeft, temp = {left + 1, SIZE(numbers) - range.SS - 1};
            else if(maxRight > value && maxRight >= maxLeft && maxRight.negative % 2 == 0)
                count = maxRight, temp = {range.FF, SIZE(numbers) - right};

            if(count >= maxCount)
                maxCount = count, best = temp;
            return ;
        }
    }
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        VI numbers(N);
        vector<pair<int, Count>> ranges(1, {-1, Count()});
        Count maxCount;
        for(int i = 0 ; i < N ; i++) {
            cin>>numbers[i];

            if(numbers[i] == 0)
                ranges.push_back({i, maxCount}), maxCount = Count();
            else if(i == N - 1)
                ranges.push_back({i + 1, maxCount + numbers[i]});
            else
                maxCount = maxCount + numbers[i];
        }

        maxCount = Count(0, 0, 0);
        PII best = {0, N};

        for(int k = 1 ; k < SIZE(ranges) ; k++) {
            if(ranges[k].SS.c_abs() > maxCount && ranges[k].SS.negative % 2 != 0)
                removeNeg(numbers, {ranges[k - 1].FF + 1, ranges[k].FF - 1}, ranges[k].SS, maxCount, best);
            else if(ranges[k].SS > maxCount)
                maxCount = ranges[k].SS, best = {ranges[k - 1].FF + 1, N - ranges[k].FF};
        }

        cout<<best.first<<" "<<best.second<<"\n";
    }
    
    return 0;
}