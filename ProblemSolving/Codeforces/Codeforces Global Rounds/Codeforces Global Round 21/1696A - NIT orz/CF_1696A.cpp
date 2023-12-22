/**
 * Title: "NIT orz", Codeforces problem. 
 * Date: Saturday, 25 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, Z;
        cin>>N>>Z;
        
        int maxNum = 0;
        for(int i = 0 ; i < N ; i++) {
            CIN(num);
            maxNum = max(maxNum, (num | Z));
        }

        cout<<maxNum<<"\n";
    }
    
    return 0;
}