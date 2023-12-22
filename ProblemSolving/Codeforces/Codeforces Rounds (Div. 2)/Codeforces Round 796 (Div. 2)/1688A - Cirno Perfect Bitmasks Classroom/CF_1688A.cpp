/**
 * Title: "Cirno Perfect Bitmasks Classroom", Codeforces problem. 
 * Date: Friday, 03 June 2022 
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
        int X;
        cin>>X;

        if(X == 1)
            cout<<"3\n";
        else
            cout<<((X & -X) == X ?  (X & -X) + 1 : (X & -X))<<"\n";
    }
    
    return 0;
}