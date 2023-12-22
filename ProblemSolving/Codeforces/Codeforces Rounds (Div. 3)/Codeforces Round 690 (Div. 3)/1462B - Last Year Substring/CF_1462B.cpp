/**
 * Title: "Last Year Substring", Codeforces problem. 
 * Date: Sunday, 05 June 2022 
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
        string str;
        cin>>N>>str;

        bool can = false;
        for(int i = 0 ; i <= 4 ; i++)
            if(str.substr(0, i) + str.substr(N - 4 + i) == "2020")
                { can = true; break; }

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}