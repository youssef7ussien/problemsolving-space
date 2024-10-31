/**
 * Title: "Social Distance", Codeforces problem. 
 * Date: Thursday, 02 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     int(1e9 + 5)
typedef long long               Long;

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, M;
        cin>>N>>M;
        
        Long sum = 0;
        int minNum = INF, maxNum = 0;
        for(int i = 0 ; i < N ; i++) {
            CIN(num);
            sum += num;
            minNum = min(minNum, num), maxNum = max(maxNum, num);
        }
        
        cout<<(sum + N - minNum + maxNum <= M ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}