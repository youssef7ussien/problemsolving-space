/**
 * Title: "Marathon", Codeforces problem. 
 * Date: Tuesday, 14 June 2022 
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
        int a, b[3];
        cin>>a>>b[0]>>b[1]>>b[2];
        
        int cnt = 0;
        for(int i = 0 ; i < 3 ; i++)
            if(a < b[i])
                cnt++;
        
        cout<<cnt<<"\n";
    }
    
    return 0;
}