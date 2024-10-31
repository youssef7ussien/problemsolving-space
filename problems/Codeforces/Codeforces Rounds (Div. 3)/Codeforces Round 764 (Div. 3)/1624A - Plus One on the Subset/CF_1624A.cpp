/**
 * Title: "Plus One on the Subset", Codeforces problem. 
 * Date: Thursday, 28 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     int(1e9+1)

typedef long long               Long;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, minNum = INF, maxNum = -INF;
        cin>>N;

        for(int i = 0 ; i < N ; i++) {
            CIN(temp);
            minNum = min(minNum, temp);
            maxNum = max(maxNum, temp);
        }

        cout<<maxNum - minNum<<"\n";
    }
    
    return 0;
}