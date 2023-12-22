/**
 * Title: "Polygon", Codeforces problem. 
 * Date: Tuesday, 10 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        vector<string> matrix(N);
        for(auto &it : matrix)
            cin>>it;
        bool can = true;

        for(int i = 0 ; i < N - 1 ; i++)
            for(int j = 0 ; j < N - 1 ; j++)
                if(matrix[i][j] == '1' && (matrix[i + 1][j] != '1' && matrix[i][j + 1] != '1'))
                    { can = false; break; }
        
        for(int i = 0 ; i < N - 1 && can ; i++)
            if(matrix[i][N - 1] == '1' && matrix[i][N - 1] != '1')
                { can = false; break; }
                
        for(int j = 0 ; j < N - 1 && can ; j++)
            if(matrix[N - 1][j] == '1' && matrix[N - 1][j] != '1')
                { can = false; break; }
        
        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}