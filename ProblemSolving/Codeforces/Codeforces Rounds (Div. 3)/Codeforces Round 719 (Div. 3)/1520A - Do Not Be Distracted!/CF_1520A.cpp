
/**
 * Title: "Do Not Be Distracted!", Codeforces problem. 
 * Date: Tuesday, 03 May 2022 
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
        cin>>N;

        bool can = true;
        char last;
        vector<bool> freq(26);
        for(int i = 0 ; i < N ; i++) {
            char ch; cin>>ch;

            if(i != 0 && last != ch && freq[ch - 'A'])
                can = false;
            else 
                freq[ch - 'A'] = true;
            
            last = ch;
        }

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}