/**
 * Title: "Binary String Reconstruction", Codeforces problem. 
 * Date: Saturday, 07 May 2022 
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
        int N0, N1, N2;
        cin>>N0>>N1>>N2;

        string result;
        for(int i = 0 ; i < N1 ; i++)
            result += ( i % 2 == 0 ? '0' : '1');
        
        cout<<string(N0, '0')
            <<result
            <<string(N2, '1')
            <<((N1 % 2 == 0 && N1 != 0) || (N0 != 0 && N1 == 0) ? '0' : '1')<<"\n";
    }
    
    return 0;
}