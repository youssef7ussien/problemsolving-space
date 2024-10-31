#include <bits/stdc++.h>

typedef long long Long;
#define MAX 1e5+1

Long maxNum(int N,std::vector<int> &freq)
{
    std::vector<Long> dp(MAX);
    dp[0]=0, dp[1]=freq[1];

    for(int i=2 ; i<MAX ;i++)
        dp[i]=std::max(dp[i-1],dp[i-2]+(Long)freq[i]*i);

    return dp[MAX-1];
}

int main()
{
    int N;
    std::cin>>N;

    std::vector<int> freq(MAX);
    for(int i=0 ; i<N ; i++)
    {
        int num; std::cin>>num;
        freq[num]++;
    }

    std::cout<<maxNum(N,freq)<<"\n";

    return 0;
}
