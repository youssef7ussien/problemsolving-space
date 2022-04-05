/**
 * Explain the problem : https://www.youtube.com/watch?v=Rmi_2e6gt5M&t
 * hint : https://www.youtube.com/watch?v=9DP0X2xlPCo&list=PLPt2dINI2MIb4OXlJ_EEwIDV9WVUpRQ5K
 * hint : https://www.geeksforgeeks.org/cpp-program-for-topological-sorting/
 */
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;

vector<bool> visited;
vector<Vector> students;
Vector result;

void topologicalSort(int student)
{
    visited[student]=true;
    for(int i=0 ; i<(int)students[student].size() ; i++)
        if(!visited[students[student][i]])
            topologicalSort(students[student][i]);

    result.push_back(student);
}

void solve(int N,vector<Vector> students)
{
    visited.resize(N+1,false);
    for(int i=1 ; i<=N ; i++)
        if(!visited[i])
            topologicalSort(i);

    Vector parent(N+1);
    int position=0;
    for(int i=result.size()-1 ; i>=0 ; i--)
    {
        parent[result[i]]=position;
        position=result[i];
    }

    for(int i=1 ; i<(int)parent.size() ; i++)
        cout<<parent[i]<<endl;
}

int main()
{
    int N,K;
    cin>>N>>K;
    students.resize(N+1);
    for(int i=1 ; i<=K ; i++)
    {
        int Wishes;
        cin>>Wishes;
        students[i].resize(Wishes);
        for(int j=0 ; j<Wishes ; j++)
            cin>>students[i][j];
    }

    solve(N,students);

    return 0;
}
