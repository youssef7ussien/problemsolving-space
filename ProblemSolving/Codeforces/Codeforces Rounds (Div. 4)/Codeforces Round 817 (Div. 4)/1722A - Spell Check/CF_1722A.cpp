/**
 * Title: "Spell Check", Codeforces problem. 
 * Date: Tuesday, 30 August 2022 
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
        int N;
        string str, name = "Timur";
        cin>>N>>str;

        sort(ALL(name)), sort(ALL(str));

        cout<<(str == name ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}