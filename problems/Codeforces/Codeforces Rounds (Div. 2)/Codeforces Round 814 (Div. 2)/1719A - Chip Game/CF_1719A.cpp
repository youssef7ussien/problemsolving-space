/**
 * Title: "Chip Game", Codeforces problem. 
 * Date: Wednesday, 17 August 2022 
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
        int n, m;
        cin>>n>>m;

        cout<<(n % 2 == m % 2 ? "Tonya" : "Burenka")<<"\n";
    }
    
    return 0;
}