// Use Floyd Warshall's
#include <iostream>
#include <vector>

#define INF 1e9

using std::cout;
using std::cin;

void printPath(std::vector<std::vector<int>> &prev,int from,int to)
{
    if(from==to)
        { cout<<" "<<from; return; }

    printPath(prev,from,prev[from][to]);
    cout<<" "<<to;
}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    int N=0, caseNum=1;
    while(cin>>N && N!=0)
    {

        std::vector<std::vector<int>> dp(N+1,std::vector<int>(N+1)), prev(N+1,std::vector<int>(N+1));
        for(int i=1 ; i<=N ; i++)
            for(int j=1 ; j<=N ; j++)
            {
                i==j ? dp[i][j]=0 : dp[i][j]=INF;
                prev[i][j]=i;
            }

        for(int i=1 ; i<=N ; i++)
        {
            int numInter;
            cin>>numInter;
            for(int j=0 ; j<numInter ; j++)
            {
                int to, delay;
                cin>>to>>delay;
                dp[i][to]=delay;
            }
        }

        for(int k=1 ; k<=N ; k++)
            for(int i=1 ; i<=N ; i++)
                for(int j=1 ; j<=N ; j++)
                    if(dp[i][j]>dp[i][k]+dp[k][j])
                        dp[i][j]=dp[i][k]+dp[k][j], prev[i][j]=prev[k][j];

        int from, to;
        cin>>from>>to;
        cout<<"Case "<<caseNum++<<": Path =";
        printPath(prev,from,to);
        cout<<"; "<<dp[from][to]<<" second delay\n";

    }
    return 0;
}
