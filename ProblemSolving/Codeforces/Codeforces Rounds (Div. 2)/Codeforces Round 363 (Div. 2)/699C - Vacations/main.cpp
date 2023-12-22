//Solution: https://www.youtube.com/watch?v=RgCn_C1rZXs

#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())
#define MAX 1e6

int main()
{
    int N;
    cin>>N;

    vector<int> days(N);
    for(auto &it : days)
        cin>>it;

    vector<vector<int>> dp(N, vector<int>(3, MAX));

    dp[0][0] = 1;

    if(days[0] == 1 || days[0] == 3)
        dp[0][1] = 0;

    if(days[0] == 2 || days[0] == 3)
        dp[0][2] = 0;

    for(int i=1 ; i<SIZE(days) ; i++)
    {
        dp[i][0] = 1 + min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);

        if(days[i] == 1 || days[i] == 3)
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);

        if(days[i] == 2 || days[i] == 3)
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    }

    cout<<min(min(dp[SIZE(days)-1][0], dp[SIZE(days)-1][1]), dp[SIZE(days)-1][2])<<"\n";

    return 0;
}
