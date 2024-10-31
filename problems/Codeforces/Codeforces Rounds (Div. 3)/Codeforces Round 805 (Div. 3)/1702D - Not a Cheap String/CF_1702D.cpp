/**
 * Title: "Not a Cheap String", Codeforces problem. 
 * Date: Saturday, 06 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        string str;
        int P;
        cin>>str>>P;

        int count = 0;
        VI freq(26);
        for(auto &it : str)
            freq[it - 'a']++, count += it - 'a' + 1;
        
        for(int i = 25 ; i >= 0 && count > P ; i--) {
            while(count > P && freq[i] > 0)
                count -= i + 1, freq[i]--;
        }

        for(auto &it : str)
            if(freq[it - 'a'] > 0)
                freq[it - 'a']--, cout<<it;
        cout<<"\n";
    }
    
    return 0;
}