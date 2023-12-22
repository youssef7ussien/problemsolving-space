/**
 * Title: "Arithmetic Array", Codeforces problem. 
 * Date: Friday, 19 August 2022 
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
        
        int sum = 0;
        for(int i = 0 ; i < N ; i++) {
            int num; cin>>num;
            sum += num;
        }

        cout<<(sum < 0 || sum < N ? 1 : sum - N)<<"\n";
    }
    
    return 0;
}