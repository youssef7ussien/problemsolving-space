#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<long long> stones(N+1), sumCosts(N+1);
    for(int i=1 ; i<=N ;i++)
    {
        cin>>stones[i];
        sumCosts[i]+=stones[i]+sumCosts[i-1];
    }

    sort(stones.begin(),stones.end());
    for(int i=1 ; i<=N ;i++)
        stones[i]+=stones[i-1];

    int M;
    cin>>M;
    while(M--)
    {
        int type, L, R;
        cin>>type>>L>>R;
        type==1 ?  cout<<sumCosts[R]-sumCosts[L-1]<<endl : cout<<stones[R]-stones[L-1]<<endl;
    }

    return 0;
}
