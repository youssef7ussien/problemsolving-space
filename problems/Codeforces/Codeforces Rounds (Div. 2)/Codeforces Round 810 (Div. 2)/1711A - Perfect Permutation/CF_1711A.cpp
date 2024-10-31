/**
 * Title: "Perfect Permutation", Codeforces problem. 
 * Date: Sunday, 24 July 2022 
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
        
        for(int i = 2 ; i <= N ; i++)
            cout<<i<<" ";
        cout<<"1\n";
    }
    
    return 0;
}