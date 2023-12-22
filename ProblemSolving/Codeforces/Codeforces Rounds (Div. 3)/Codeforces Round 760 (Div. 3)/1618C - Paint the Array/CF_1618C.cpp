/**
 * Title: "Paint the Array" problem. 
 * Date: Tuesday, 14 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long         Long;
typedef pair<int, int>    PII;
typedef vector<int>       VI;
typedef vector<Long>      VL;

Long getGCD(const VL &numbers, int start)
{
    Long num = numbers[start];
    for(int i=start+2 ; i<SIZE(numbers) ; i+=2)
        num = __gcd(num, numbers[i]);
    
    return num;
}

bool check(const VL &numbers, const Long &number, int start)
{
    for(int i=start ; i<SIZE(numbers) ; i+=2)
        if(numbers[i] % number == 0)
            return false;
    
    return true; 
}

Long solve(const VL &numbers)
{
    Long num = getGCD(numbers, 0);
    if(num != 1 && check(numbers, num, 1))
        return num;

    num = getGCD(numbers, 1);
    if(num != 1 && check(numbers, num, 0))
        return num;

    return 0;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T)
    {
        int N; cin>>N;

        VL numbers(N);
        for(auto &it : numbers)
            cin>>it;

        cout<<solve(numbers)<<"\n";
    }
    
    return 0;
}