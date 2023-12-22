#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())
typedef long long Long;

int getValidPower(int factor,Long N, bool isNegative)
{
    int counter=1; Long result=factor;

    while(result <= N)
    {
        if(result==N)
            return (!isNegative || counter%2!=0) ? counter : -1;

        result*=factor, counter++;
    }

    return -1;
}

int getPerfectPower(Long N, bool isNegative)
{
    int maxPower=1;

    for(Long i=2 ; i*i<=N ; i++)
        if(N%i==0)
            maxPower=max(getValidPower(i, N, isNegative), maxPower);

    return maxPower;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Long N;
    while((cin>>N) && N!=0)
    {

        cout<<getPerfectPower(abs(N), (N < 0))<<"\n";
    }
    return 0;
}
