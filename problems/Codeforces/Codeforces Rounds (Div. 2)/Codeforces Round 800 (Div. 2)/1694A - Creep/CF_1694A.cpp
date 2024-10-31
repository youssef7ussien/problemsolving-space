/**
 * Title: "Creep", Codeforces problem. 
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
        int A, B;
        cin>>A>>B;

        string result;
        while(A > 0 || B > 0) {
            if(A > 0)
                result += "0", A--;
            if(B > 0)
                result += "1", B--;
        }

        cout<<result<<"\n";
    }
    
    return 0;
}