#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())

void createPrimeFactors(int N,vector<int> &factors)
{
    for(int i=2 ; i*i<=N ; i++)
        while(N%i==0)
            N/=i, factors.push_back(i);

    if(N!=1)
        factors.push_back(N);
}

int main()
{
    int N, K;
    cin>>N>>K;

    vector<int> factors;

    createPrimeFactors(N, factors);

    if(K > SIZE(factors))
        { cout<<"-1"<<"\n"; return 0; }

    int remaining = N;
    for(int i=0 ; i<K-1 ; i++)
        cout<<factors[i]<<" ", remaining/=factors[i];

    cout<<remaining<<"\n";

    return 0;
}
