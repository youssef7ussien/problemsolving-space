/**
 * Title: "Special Permutation", Codeforces problem. 
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
        int N;
        cin>>N;
        if(N < 4)
            cout<<"-1\n";
        else {
            for(int i = N - N % 2 ; i > 4 ; i -= 2)
                cout<<i<<" ";
            cout<<"2 4 ";
            for(int i = 1 ; i <= N ; i += 2)
                cout<<i<<" ";
            cout<<"\n";
        }
    }
    
    return 0;
}