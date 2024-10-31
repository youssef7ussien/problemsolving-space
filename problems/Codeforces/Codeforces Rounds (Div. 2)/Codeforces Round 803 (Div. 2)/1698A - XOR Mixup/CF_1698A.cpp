/**
 * Title: "XOR Mixup", Codeforces problem. 
 * Date: Tuesday, 28 June 2022 
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
        
        int last;
        for(int i  = 0 ; i < N ; i++)
            cin>>last;

        cout<<last<<"\n";
    }
    
    return 0;
}