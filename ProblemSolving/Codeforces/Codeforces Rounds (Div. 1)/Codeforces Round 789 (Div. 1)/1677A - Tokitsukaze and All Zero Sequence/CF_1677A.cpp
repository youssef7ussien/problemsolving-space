/**
 * Title: "Tokitsukaze and All Zero Sequence", Codeforces problem. 
 * Date: Sunday, 08 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI freq(101);
        bool found = false;

        for(int i =0 ; i < N ; i++) {
            CIN(num);
            freq[num]++;
        }

        for(auto &it : freq)
            if(it >= 2)
                { found = true; break; }
        
        cout<<(freq[0] > 0 ? N - freq[0] : found ? N : N + 1)<<"\n";
        
    }
    
    return 0;
}