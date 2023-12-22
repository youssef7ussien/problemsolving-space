/**
 * Title: "Double Strings", Codeforces problem. 
 * Date: Thursday, 21 July 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        vector<string> strings(N);
        map<string, bool> freq;
        for(auto &it : strings) {
            cin>>it;
            freq[it] = true;
        }

        for(auto &it : strings) {
            bool can = false;
            for(int i = 0 ; i  < LEN(it) ; i++)
                if(freq[it.substr(0, i)] && freq[it.substr(i, LEN(it) - i)])
                    { can = true; break; }
                    
            cout<<(can ? 1 : 0);
        }
        cout<<"\n";
    }
    
    return 0;
}