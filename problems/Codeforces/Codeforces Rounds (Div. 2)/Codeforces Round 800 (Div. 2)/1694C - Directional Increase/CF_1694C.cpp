/**
 * Title: "Directional Increase", Codeforces problem. 
 * Date: Thursday, 16 June 2022 
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
        
        long long sum = 0;
        bool can = true;
        for(int i = 0 ; i < N ; i++) {
            int num; 
            cin>>num;
            
            if(sum == 0 && i > 0 && num > 0)
                can = false;
            
            sum += num;

            if(sum < 0)
                can = false;
        }

        cout<<(!can || sum > 0 ? "NO" : "YES")<<"\n";
    }
    
    return 0;
}