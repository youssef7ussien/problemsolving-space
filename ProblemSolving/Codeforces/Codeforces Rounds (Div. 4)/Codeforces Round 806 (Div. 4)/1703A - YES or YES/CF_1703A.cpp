/**
 * Title: "YES or YES", Codeforces problem. 
 * Date: Thursday, 21 July 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        string str;
        cin>>str;

        transform(ALL(str), str.begin(), ::tolower);

        cout<<(str == "yes" ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}