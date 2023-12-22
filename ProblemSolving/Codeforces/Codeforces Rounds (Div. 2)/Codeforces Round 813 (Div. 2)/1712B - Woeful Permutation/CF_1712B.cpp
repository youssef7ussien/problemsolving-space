/**
 * Title: "Woeful Permutation", Codeforces problem. 
 * Date: Saturday, 13 August 2022 
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

        if(N % 2 != 0)
            cout<<"1 ";

        for(int i = 1 + (N % 2 != 0) ; i <= N ; i += 2)
          cout<<i + 1<<" "<<i<<" ";
        cout<<"\n";

    }
    
    return 0;
}