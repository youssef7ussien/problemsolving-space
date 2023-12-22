/**
 * hint : https://www.youtube.com/watch?v=9DP0X2xlPCo&list=PLPt2dINI2MIb4OXlJ_EEwIDV9WVUpRQ5K
 * hint : https://www.geeksforgeeks.org/cpp-program-for-topological-sorting/
 */
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;

vector<bool> visited;
vector<Vector> tasks;
Vector result;

void topologicalSort(int task)
{
    visited[task]=true;

    for(int i=0 ; i<(int)tasks[task].size() ; i++)
        if(!visited[tasks[task][i]])
            topologicalSort(tasks[task][i]);

    result.push_back(task);
}

void solve(int N,vector<Vector> tasks)
{
    visited.clear(); result.clear();
    visited.resize(N+1,false);

    for(int i=1 ; i<=N ; i++)
        if(!visited[i])
            topologicalSort(i);

    for(int i=(int)result.size()-1 ; i>=0 ; i--)
        i==0 ? cout<<result[i]<<endl : cout<<result[i]<<" ";

}

int main()
{
    int N,M;
    while(cin>>N>>M && N!=0)
    {
        tasks.clear(); tasks.resize(N+1);
        while(M--)
        {
            int x,y;
            cin>>x>>y;
            tasks[x].push_back(y);
        }
        solve(N,tasks);
    }

    return 0;
}
