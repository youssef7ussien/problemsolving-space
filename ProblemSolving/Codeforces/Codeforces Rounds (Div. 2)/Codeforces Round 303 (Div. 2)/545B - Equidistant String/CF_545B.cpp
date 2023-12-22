/**
 * Title: "Equidistant String", Codeforces problem. 
 * Date: Tuesday, 10 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;


int main()
{
    FAST_IO;
    
    string s, t;
    cin>>s>>t;
    
    string p = s;
    int diff = 0;

    for(int i = 0 ; i < LEN(s) ; i++) {
        if(s[i] != t[i])
            p[i] = (diff % 2 ? s[i] : t[i]), diff++;
    }

    cout<<(diff % 2 ? "impossible" : p)<<"\n";
    return 0;
}