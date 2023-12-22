/**
 * Title: "Same Differences", Codeforces problem. 
 * Date: Tuesday, 03 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        Long counter = 0;
        map<int, int> freq;
        for(int i = 0 ; i < N ; i++) {
            CIN(num);
            counter += freq[num - i]++;
        }
            
        cout<<counter<<"\n";
    }
    
    return 0;
}