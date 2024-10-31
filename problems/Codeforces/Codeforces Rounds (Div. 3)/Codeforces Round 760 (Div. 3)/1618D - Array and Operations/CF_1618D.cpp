/**
 * Title: "Array and Operations" problem. 
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
typedef vector<int>       VI;

int solve(int K, const VI &numbers)
{
    int score = 0, L = SIZE(numbers)-K-1, R = SIZE(numbers)-1;

    while(K--)
        score += (numbers[L--] / numbers[R--]);

    while(L >= 0)
        score += numbers[L--];

    return score;
}

int main()
{   
    FAST_IO;

    TEST_CASES(T)
    {
        int N, K;
        cin>>N>>K;

        VI numbers(N);
        for(auto &it : numbers)
            cin>>it;
        
        sort(ALL(numbers));

        cout<<solve(K, numbers)<<"\n";
    }
    
    return 0;
}