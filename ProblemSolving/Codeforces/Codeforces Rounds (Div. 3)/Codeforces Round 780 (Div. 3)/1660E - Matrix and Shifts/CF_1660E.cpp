/**
 * Title: "Matrix and Shifts", Codeforces problem. 
 * Date: Thursday, 05 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        int ones = 0, result = INF;
        vector<VI> matrix(N, VI(N));
        
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < N ; j++) {
                char ch; cin>>ch;
                matrix[i][j] = ch - '0';
                ones += matrix[i][j];
            }

        for(int i = 0 ; i < N ; i++) {
            int count1 = 0, count0 = 0;
            for(int j = 0 ; j < N ; j++)
                matrix[j][(i + j) % N] == 1 ? count1++ : count0++;
            
            result = min(result, count0 + ones - count1);
        }
        
        cout<<result<<"\n";
    }
    
    return 0;
}