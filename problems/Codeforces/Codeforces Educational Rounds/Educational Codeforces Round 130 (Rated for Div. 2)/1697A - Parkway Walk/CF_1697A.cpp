/**
 * Title: "Parkway Walk", Codeforces problem. 
 * Date: Tuesday, 14 June 2022 
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
        int N, M;
        cin>>N>>M;

        int sum = 0;
        for(int i = 0 ; i < N ; i++) {
            CIN(num);
            sum += num;
        }

        cout<<max(0, sum - M)<<"\n";
    }
    
    return 0;
}