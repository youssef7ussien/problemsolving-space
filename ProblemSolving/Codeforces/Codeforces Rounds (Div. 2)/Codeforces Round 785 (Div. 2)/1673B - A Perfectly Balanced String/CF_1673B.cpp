/**
 * Title: "A Perfectly Balanced String", Codeforces problem. 
 * Date: Sunday, 01 May 2022 
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
        string str;
        cin>>str;
        
        vector<bool> freq(26);
        int i = 0;
        for(i = 0 ; i < SIZE(str) ; i++) {
            if(!freq[str[i] - 'a'])
                freq[str[i] - 'a'] = true;
            else
                break;
        }

        bool can = true;
        for(int j = i; j < SIZE(str) ; j++)
            if(str[j] != str[j - i]) 
                { can = false; break; }

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}