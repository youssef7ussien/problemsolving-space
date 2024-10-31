/**
 * Title: "Optimal Reduction", Codeforces problem. 
 * Date: Sunday, 07 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        bool can = true, increase = true;
        for(int i = 0, last = 0 ; i < N ; i++) {
            int num; cin>>num;

            if(i != 0 && (!increase && num > last))
                can = false;
            else if(i != 0 && num < last)
                increase = false;
            
            last = num;
        }
        
        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}