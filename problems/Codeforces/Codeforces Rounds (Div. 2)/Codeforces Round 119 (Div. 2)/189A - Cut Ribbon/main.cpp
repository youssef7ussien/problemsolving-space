#include <bits/stdc++.h>

using namespace std;

#define NEG_INF (-1e8)

vector<int> dp, lengths(3,0);

int calcRibbonPieces(int n)
{
    if(n==0) return 0;

    if(dp[n]!=-1) return dp[n];

    int result=NEG_INF;
    for(auto &it : lengths)
        if(n>=it) result=max(result,calcRibbonPieces(n-it)+1);

    return dp[n]=result;
}

int main()
{
    int n;
    cin>>n>>lengths[0]>>lengths[1]>>lengths[2];

    dp.resize(n+1,-1);

    cout<<calcRibbonPieces(n)<<"\n";

    return 0;
}
