/**
 * Title: "awoo's Favorite Problem", Codeforces problem. 
 * Date: Tuesday, 14 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


bool solve(string s, string t)
{
    for(int i = 0, j = 0 ; i < LEN(s) ; i++) {
        if(s[i] == t[i])
            continue;
        
        j = max(i, j);

        if(s[i] == 'a' && t[i] == 'b') {    
            while(j < LEN(s) && s[j] == 'a') j++;
            
            if(s[j] != 'b' || j == LEN(s))
                return false;
            
            swap(s[i], s[j]);
        }
        else if(s[i] == 'b' && t[i] == 'c') {
            while(j < LEN(s) && s[j] == 'b') j++;
            
            if(s[j] != 'c' || j == LEN(s))
                return false;
            
            swap(s[i], s[j]);
        }
        else
            return false;
    }

    return true;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        string s, t;
        cin>>N>>s>>t;
        
        cout<<(solve(s, t) ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}