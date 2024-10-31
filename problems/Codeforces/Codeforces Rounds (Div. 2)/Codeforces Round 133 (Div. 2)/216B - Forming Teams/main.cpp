/**
 *  Explain the problem: https://www.youtube.com/watch?v=O4rahDYs9-c&t=550s
 *  hint: https://www.geeksforgeeks.org/bipartite-graph/
 */
#include <iostream>
#include <vector>

using namespace std;

#define SIZE(v) ((int)v.size())
enum status {PATH=0, CYCLE=1};
vector<vector<int>> students;
vector<bool> visited;

status DFS(int student,int parent,int &counter)
{
    if(visited[student])
        return CYCLE;

    visited[student]=true;
    for(auto it : students[student])
        if(it!=parent)
        {
            counter++;
            if(DFS(it,student,counter)==CYCLE)
                return CYCLE;
        }

    return PATH;
}

int calculateSendedStudents(vector<vector<int>> students)
{
    visited.resize(students.size(),false);
    int numRemoved=0;
    for(int i=0 ; i<SIZE(students) ; i++)
        if(!visited[i])
        {
            int counter=0;
            if(DFS(i,-1,counter)==CYCLE)
                numRemoved+=(counter%2==1);
        }

    return (SIZE(students)-numRemoved)%2==0 ? numRemoved : numRemoved+1;
}

int main()
{
    int N=0, M=0;
    cin>>N>>M;
    students.resize(N);
    for(int i=0 ; i<M ; i++)
    {
        int X=0,Y=0;
        cin>>X>>Y;
        students[X-1].push_back(Y-1);
        students[Y-1].push_back(X-1);
    }

    cout<<calculateSendedStudents(students)<<endl;

    return 0;
}
