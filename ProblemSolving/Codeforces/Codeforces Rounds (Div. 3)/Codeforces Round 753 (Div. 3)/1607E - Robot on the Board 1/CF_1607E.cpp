/**
 * Title: "Robot on the Board 1" problem. 
 * Date: Tuesday, 14 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)     freopen(file, "r", stdin)
#define FILE_OUT(file)    freopen(file, "w", stdout)
#define INF               1e9

typedef long long         Long;
typedef pair<int, int>    PII;

PII solve(int N, int M, string commands)
{
    int X = 0, Y = 0;
    //          L, R           D, U            row, column
    PII maxX = {0, 0}, maxY = {0, 0}, result = {1, 1};

    for(auto &it : commands)
    {
        X += (it == 'L' ? -1 : it == 'R' ? 1 : 0);
        Y += (it == 'D' ? -1 : it == 'U' ? 1 : 0);
        maxX = {min(X, maxX.first), max(X, maxX.second)};
        maxY = {min(Y, maxY.first), max(Y, maxY.second)};

        if(maxX.second - maxX.first + 1 > M || maxY.second - maxY.first + 1 > N)
            return result;

        result = {abs(maxY.second) + 1, abs(maxX.first) + 1};
    }

    return result;
}

int main()
{
    #ifdef DEBUG
        FILE_IN("__CF_1607E_input.txt");
        FILE_OUT("__CF_1607E_output.txt");
    #endif
    
    FAST_IO;

    TEST_CASES(T)
    {
        int N, M;
        string commands;
        cin>>N>>M>>commands;

        PII result = solve(N, M, commands);

        cout<<result.first<<" "<<result.second<<"\n";
    }

    return 0;
}