/**
 * Title: "Cyclic Components", Codeforces problem. 
 * Date: Monday, 15 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

vector<vector<int>> adj;
vector<bool> visited;

bool DFS(int v)
{
    visited[v] = true;
    bool isCyclic = (LEN(adj[v]) == 2);
    
    for(auto &it : adj[v])
        if(!visited[it])
            isCyclic &= DFS(it);
    
    return isCyclic;
}

int main()
{
    FAST_IO;
    
    int N, M;
    cin>>N>>M;

    adj.resize(N + 1), visited.resize(N + 1);
    for(int i = 0 ; i < M ; i++) {
        int v, u;
        cin>>v>>u;
        adj[v].push_back(u), adj[u].push_back(v);
    }

    int counter = 0;
    for(int i = 1 ; i <= N ; i++)
        counter += (visited[i] == 0 && DFS(i));
    
    cout<<counter<<"\n";
    return 0;
}