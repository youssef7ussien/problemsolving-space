#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())
typedef long long Long;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T=0;
    cin>>T;

    while(T--)
    {
        int N;
        cin>>N;
        vector<Long> sequence(N);

        for(auto &it : sequence)
            cin>>it;

        sort(sequence.begin(), sequence.end());

        double sum=0, maxNum=sequence[N-1] * 1.0d;
        for(int i=0 ; i<N-1 ; i++)
            sum+=sequence[i];

        cout<<fixed<<setprecision(9)<<(sum/(N-1) + maxNum)<<"\n";
    }

    return 0;
}
