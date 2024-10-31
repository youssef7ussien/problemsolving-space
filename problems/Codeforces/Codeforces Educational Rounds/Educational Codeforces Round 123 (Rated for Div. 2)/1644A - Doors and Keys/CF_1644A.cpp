/**
 * Title: "Doors and Keys", Codeforces problem. 
 * Date: Tuesday, 22 February 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;


bool solve(const string &str) {
    unordered_map<int, bool> keys;
    
    for(auto &it : str) {
        if(it == 'r' || it == 'g' || it == 'b')
            keys[it] = true;
        else if(!keys[it + 32])
            return false;
    }
    
    return true;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        string str;
        cin>>str;
        
        cout<<(solve(str) ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}