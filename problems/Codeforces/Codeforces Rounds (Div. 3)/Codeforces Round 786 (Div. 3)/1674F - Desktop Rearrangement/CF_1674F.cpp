/**
 * Title: "Desktop Rearrangement", Codeforces problem. 
 * Date: Tuesday, 03 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    int N, M, Q;
    cin>>N>>M>>Q;

    vector<vector<char>> grid(N + 1, vector<char>(M + 1));
    VI column(M + 1);
    int countStars = 0;

    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= M ; j++) {
            cin>>grid[i][j];
            if(grid[i][j] == '*')
                column[j]++, countStars++;
        }

    while(Q--) {
        int X, Y;
        cin>>X>>Y;

        if(grid[X][Y] == '.')
            grid[X][Y] = '*', column[Y]++, countStars++;
        else
            grid[X][Y] = '.', column[Y]--, countStars--;
        
        int counter = countStars;
        for(int i = 1 ; i <= countStars / N ; i++)
            counter -= column[i];

        for(int i = 1 ; i <= countStars % N ; i++)
            counter -= (grid[i][countStars / N + 1] == '*');

        cout<<counter<<"\n";
    }
    
    return 0;
}