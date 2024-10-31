/**
 * Title: "Hungry Student Problem", Codeforces problem. 
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
        int X;
        cin>>X;

        cout<<( X > 11 || X == 10 || (X <= 11 && (X % 3 == 0 || X % 7 == 0)) ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}