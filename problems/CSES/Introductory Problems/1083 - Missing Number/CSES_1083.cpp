/**
 * Title: "Missing Number", CSES problem. 
 * Date: Thursday, 02 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;


int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    Long sum = 0;
    for(int i = 0 ; i < N - 1 ; i++) {
        int num; cin>>num;
        sum += num;
    }
    
    cout<<(1LL * N * (N + 1) / 2 - sum)<<"\n";
    return 0;
}