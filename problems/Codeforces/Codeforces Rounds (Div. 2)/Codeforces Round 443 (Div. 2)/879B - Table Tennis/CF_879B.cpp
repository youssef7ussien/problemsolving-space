/**
 * Title: "Table Tennis", Codeforces problem. 
 * Date: Friday, 17 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long         Long;

int solve(int N, Long K, queue<int> players)
{
    if(K >= N)
        return N;
    
    Long counter = 0;
    int playerX = players.front(), playerY;
    players.pop();

    while(counter < K) {
        playerY = players.front(), players.pop();

        if(playerX > playerY)
            players.push(playerY), counter++;
        else
            players.push(playerX), playerX=playerY, counter=1;
    }

    return playerX;
}

int main()
{   
    FAST_IO;

    int N; 
    Long K;
    cin>>N>>K;

    queue<int> players;
    for(int i=0 ; i<N ; i++)
    {
        int temp; cin>>temp;

        players.push(temp);
    }
    
    cout<<solve(N, K, players)<<"\n";
    return 0;
}