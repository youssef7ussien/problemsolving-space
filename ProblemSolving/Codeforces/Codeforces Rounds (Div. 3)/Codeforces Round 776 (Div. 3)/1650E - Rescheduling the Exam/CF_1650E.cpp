/**
 * Title: "Rescheduling the Exam", Codeforces problem. 
 * Date: Tuesday, 26 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;


bool check(const VI &days, int D, int middle)
{
    for(int i = 1 ; i < SIZE(days) ; i++)
        if(days[i] - days[i - 1] - 1 < middle)
            return false;
            
    for(int i = 1 ; i < SIZE(days) ; i++)
        if(days[i] - days[i - 1] - 1 > 2 * middle)
            return true;
    
    return (D - days.back() - 1 >= middle);
}

int binarySearch(const VI &days, int minDiff, int D)
{
    int left = minDiff, right = D, result = 0;
    while(left <= right) {
        int middle = left + (right - left) / 2;

        if(check(days, D, middle))
            result = middle, left = middle + 1;
        else
            right = middle - 1;
    }

    return result;
}

int solve(const VI &days, int minDiff, int D, PII index)
{
    VI temp = days;
    temp.erase(temp.begin() + index.first);
    
    int result = binarySearch(temp, minDiff, D);
    
    if(index.second != 0) {
        temp = days;
        temp.erase(temp.begin() + index.second);

        return max(result, binarySearch(temp, minDiff, D));
    }

    return result;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, D;
        cin>>N>>D;

        VI days(N + 1);
        PII index = {-1, -1}, minDiff = {INF, 0};
        
        for(int i = 1 ; i <= N ; i++) {
            cin>>days[i];
            
            if(days[i] - days[i - 1] - 1 < minDiff.first)
                minDiff = {days[i] - days[i - 1] - 1, 0}, index = {i, i - 1};
            else if(days[i] - days[i - 1] - 1 == minDiff.first)
                minDiff.second++;
        }

        if(minDiff.second > 2)
            cout<<minDiff.first<<"\n";
        else
            cout<<solve(days, minDiff.first, D, index)<<"\n";
    }
    
    return 0;
}