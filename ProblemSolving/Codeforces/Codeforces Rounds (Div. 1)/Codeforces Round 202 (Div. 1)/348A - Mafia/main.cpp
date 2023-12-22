#include <bits/stdc++.h>

using namespace std;
typedef long long Long;
#define SIZE(v) ((int)v.size())

bool check(const vector<int> &rounds,const Long &sum,Long num)
{
    for(auto &it : rounds)
        if(it > num)
            return false;

    return (SIZE(rounds)-1)*num >= sum;
}

int minNumRounds(const vector<int> &rounds,const Long &sum)
{
    Long left=0, right=2e9;

    while(left<right)
    {
        Long middle=(left+right)/2;

        check(rounds, sum, middle) ? right=middle : left=middle+1;
    }

    return right;
}

int main()
{
    int N;
    cin>>N;

    vector<int> rounds(N);
    Long sum=0;

    for(auto &it : rounds) {
        cin>>it;
        sum+=it;
    }

    cout<<minNumRounds(rounds, sum)<<"\n";

    return 0;
}
