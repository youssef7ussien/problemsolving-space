/**
 * Title: "Number Spiral", CSES problem. 
 * Date: Thursday, 02 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        Long Y, X;
        cin>>Y>>X;
        
        if((Y > X && Y % 2 == 0) || (X > Y && X % 2 != 0))
            cout<<(max(Y, X) * max(Y, X) - (min(Y, X) - 1))<<"\n";
        else 
            cout<<(max(Y, X) * max(Y, X) - ((max(Y, X) - 1) * 2 - (min(Y, X) - 1)))<<"\n";
    }
    
    return 0;
}