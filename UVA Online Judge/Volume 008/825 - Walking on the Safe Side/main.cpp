#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void initVector(vector<vector<int>> &matrix,int W,int N)
{
    for(int i=0 ; i<=W ; i++)
        matrix[i].resize(N+1,0);
    matrix[0][1]=1;
}
void inputLines(vector<vector<int>> &matrix,int W,int N)
{
    for(int i=1 ; i<=W ; i++)
    {
        int x,y;
        string line;
        getline(cin, line);
        istringstream sin(line);
        sin>>x;
        while (sin>>y)
            matrix[x][y]=-1;
    }
}

int countTracks(vector<vector<int>> &matrix,int W,int N)
{
    for(int i=1 ; i<=W ; i++)
    {
        for(int j=1 ; j<=N ; j++)
        {
            if(matrix[i][j] == -1)
                continue;
            if(matrix[i][j-1]!=-1)
                matrix[i][j]+=matrix[i][j-1];
            if(matrix[i-1][j]!=-1)
                matrix[i][j]+=matrix[i-1][j];
        }
    }
    return matrix[W][N];
}

int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        int W,N;
        cin>>W>>N;
        cin.ignore();
        vector<vector<int>> matrix(W+1);

        initVector(matrix,W,N);
        inputLines(matrix,W,N);
        t ? cout<<countTracks(matrix,W,N)<<endl<<endl : cout<<countTracks(matrix,W,N)<<endl;
    }
    return 0;
}
