#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())

long long numberOfSeconds(const vector<int> &potatos,int H,int K)
{
    long long current_H=0, seconds=0;

    for(int i=0 ; i<SIZE(potatos) ; i++)
    {
        current_H+=potatos[i];
        if(current_H > H)
            current_H=potatos[i], seconds++;

        seconds+=current_H / K;
        current_H%=K;
    }

    return seconds + (current_H>0);
}

int main()
{
    int N, H, K;
    cin>>N>>H>>K;

    vector<int> potatos(N);
    for(auto &it : potatos)
        cin>>it;

    cout<<numberOfSeconds(potatos, H, K)<<"\n";

    return 0;
}
