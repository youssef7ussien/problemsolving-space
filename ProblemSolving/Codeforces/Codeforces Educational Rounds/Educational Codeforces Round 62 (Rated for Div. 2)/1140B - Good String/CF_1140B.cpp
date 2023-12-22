/**
 * Title: "Good String", Codeforces problem. 
 * Date: Monday, 08 August 2022 
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
        
        cout<<min(str.find_first_of('>'), N - 1 - str.find_last_of('<'))<<"\n";
    }
    
    return 0;
}