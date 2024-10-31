/**
 * Title: "Where's the Bishop", Codeforces problem. 
 * Date: Tuesday, 14 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second

typedef pair<int, int>          PII;


PII solve(const vector<string> &grid)
{
    int i = 1, j = 1;
    for(; i <= 7 ; i++)
        for(j = 1 ; j <= 7 ; j++)
            if(grid[i][j] == '#' 
                && grid[i - 1][j - 1] == '#' && grid[i + 1][j + 1] == '#' 
                && grid[i - 1][j + 1] == '#' && grid[i + 1][j - 1] == '#')
                return {i + 1, j + 1};

    return {i + 1, j + 1};
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        vector<string> grid(8);
        for(auto &it : grid)
            cin>>it;

        PII ans = solve(grid);
        cout<<ans.FF<<" "<<ans.SS<<"\n";
    }
    
    return 0;
}