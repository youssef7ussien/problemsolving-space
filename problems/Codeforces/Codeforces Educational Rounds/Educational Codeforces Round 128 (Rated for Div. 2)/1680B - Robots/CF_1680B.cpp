/**
 * Title: "Robots", Codeforces problem. 
 * Date: Friday, 13 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int n, m;
        cin>>n>>m;
        vector<string> matrix(n);
        for(auto &it : matrix)
            cin>>it;
        
        PII left = {n, m}, top = {n, 0};
        for(int i = n - 1 ; i >= 0 ; i--)
            for(int j = m - 1 ; j >= 0 ; j--) {
                if(matrix[i][j] == 'R') {
                    if(left.FF >= i && left.SS >= j)
                        left = {i, j};
                    if(top.FF >= i)
                        top = {i, j};
                }
            }
        
        cout<<(left == top ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}