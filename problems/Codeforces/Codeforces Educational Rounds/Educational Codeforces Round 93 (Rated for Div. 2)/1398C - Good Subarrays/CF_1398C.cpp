/**
 * Title: "Good Subarrays", Codeforces problem. 
 * Date: Friday, 06 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        Long prefix = 0, counter = 0;
        map<Long, Long> freq;
        freq[0] = 1;
        
        for(int i = 1 ; i <= N ; i++) {
            char ch; cin>>ch;
            
            prefix += int(ch - '0'), counter += freq[prefix - i]++;
        }

        cout<<counter<<"\n";
    }
    
    return 0;
}