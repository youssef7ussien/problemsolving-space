/**
 * Title: "Polycarp and Coins", Codeforces problem. 
 * Date: Monday, 02 May 2022 
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
        
        cout<<N / 3 + (N % 3 == 1)<<" "<<N / 3 + (N % 3 == 2)<<"\n";
        
    }
    
    return 0;
}