#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define SIZE(v) ((int)v.size())

int minNumberOfOperations(int N,vector<int> &sequence)
{
    sort(sequence.begin(),sequence.end());

    int dif=N-SIZE(sequence), result=1e9+7;
    for(int i=SIZE(sequence)-1 ; i>=0 ; i--)
        result=min(result,dif+(sequence[i]-i-1)+(SIZE(sequence)-i-1));

    return min(result,N+1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("task.in","r",stdin);

    int T; cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int> sequence;
        map<int,bool> check;
        for(int i=0 ; i<N ;i++)
        {
            int x;
            cin>>x;
            if(!check[x])
                check[x]=true, sequence.push_back(x);
        }

        cout<<minNumberOfOperations(N,sequence)<<"\n";
    }
    return 0;
}
