#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<pair<int,int>>> Vector;

int maxValue(const int &U,const int &K,const Vector &nodes) // BFS graph
{
    int result=0;
    queue<int> que;
    vector<int> cost(nodes.size());

    que.push(U), cost[U]=1;
    while(que.size())
    {
        int current=que.front();
        que.pop();

        for(auto it : nodes[current])
        {
            if(cost[current]<=K)
                result=max(result,it.second);
            if(cost[it.first]) continue;

            cost[it.first]=cost[current]+1, que.push(it.first);
        }
    }

    return result;
}

int main()
{
    freopen("path.in","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int N, M, U, K; // L => It has no use
        cin>>N>>M>>U>>K>>K;

        Vector nodes(N+1);
        for(int i=0 ; i<M ; i++)
        {
            int X,Y,W;
            cin>>X>>Y>>W;
            nodes[X].push_back(make_pair(Y,W));
            nodes[Y].push_back(make_pair(X,W));
        }

        cout<<maxValue(U,K,nodes)<<"\n";
    }

    return 0;
}
