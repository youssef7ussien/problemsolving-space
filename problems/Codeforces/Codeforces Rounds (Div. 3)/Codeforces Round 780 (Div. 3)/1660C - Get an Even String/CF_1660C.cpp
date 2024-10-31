/**
 * Title: "Get an Even String", Codeforces problem. 
 * Date: Thursday, 31 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef vector<int>             VI;

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        string str;
        cin>>str;
        
        int counter = SIZE(str);
        map<int, int> freq;
        for(auto &it : str)
            if(++freq[it] == 2) {
                counter -= 2;
                freq.clear();
            }

        cout<<counter<<"\n";
    }
    
    return 0;
}