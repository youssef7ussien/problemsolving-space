#include <bits/stdc++.h>

using namespace std;
typedef long long Long;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T=0;
    cin>>T;

    while(T--)
    {
        int N, K;
        cin>>N>>K;

        vector<pair<int, int>> sequence(N);

        for(int i=0 ; i<N ; i++)
        {
            cin>>sequence[i].first;
            sequence[i].second=i;
        }

        sort(sequence.begin(), sequence.end());

        int counter=1;

        for(int i=0 ; i<N-1 ; i++)
            if(sequence[i].second+1 != sequence[i+1].second)
                counter++;

        cout<<(counter <= K ? "Yes" : "No")<<"\n";
    }

    return 0;
}
