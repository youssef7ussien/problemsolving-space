/**
 * Title: "Beat The Odds", Codeforces problem. 
 * Date: Wednesday, 01 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        int counter = 0;
        for(int i = 0 ; i < N ; i++) {
            int num; cin>>num;
            counter += (num % 2 == 1);
        }
            
        cout<<min(counter, N - counter)<<"\n";
    }
    
    return 0;
}