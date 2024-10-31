/**
 * Title: "Replace With the Previous, Minimize", Codeforces problem. 
 * Date: Friday, 06 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, K;
        string str;
        cin>>N>>K>>str;

        unordered_map<char, bool> freq;
        for(auto &it : str) {
            while(it > 'a') {
                if(freq[it])
                    { it--; continue; }
                
                if(K == 0)
                    break;

                freq[it--] = true, K--;
            }
        }

        cout<<str<<"\n";
    }
    
    return 0;
}