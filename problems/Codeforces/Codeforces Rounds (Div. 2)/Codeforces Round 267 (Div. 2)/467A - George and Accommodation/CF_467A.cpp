/**
 * Title: "George and Accommodation", Codeforces problem. 
 * Date: Tuesday, 29 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    int counter = 0;
    TEST_CASES(T) {
        int p, q;
        cin>>p>>q;
        counter += (q - p >= 2);
    }
    
    cout<<counter<<"\n";
    return 0;
}