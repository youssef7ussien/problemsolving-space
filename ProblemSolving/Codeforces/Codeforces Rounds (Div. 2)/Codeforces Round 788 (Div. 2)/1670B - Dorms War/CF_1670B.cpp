/**
 * Title: "Dorms War", Codeforces problem. 
 * Date: Friday, 13 May 2022 
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
        int N, K;
        string str;
        cin>>N>>str>>K;

        map<char, bool> freq;
        for(int i = 0 ; i < K ; i++) {
            char ch; cin>>ch;
            freq[ch] = true;
        }

        int result = 0, last = 0;
        for(int i = 0 ; i < N ; i++)
            if(freq[str[i]])
                result = max(result, i - last), last = i;
        
        cout<<result<<"\n";
    }
    
    return 0;
}