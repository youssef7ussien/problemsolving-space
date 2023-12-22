/**
 * Title: "Lex String", Codeforces problem. 
 * Date: Monday, 13 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, M, K;
        string A, B, result = "";
        cin>>N>>M>>K>>A>>B;

        sort(ALL(A)), sort(ALL(B));
        
        int i = 0, j = 0, cntA = 0, cntB = 0;
        while(i < N && j < M) {
            if((A[i] < B[j] && cntA < K) || cntB == K)
                result += A[i], i++, cntA++, cntB = 0;
            else
                result += B[j], j++, cntA = 0, cntB++;
        }

        cout<<result<<"\n";
    }
    
    return 0;
}