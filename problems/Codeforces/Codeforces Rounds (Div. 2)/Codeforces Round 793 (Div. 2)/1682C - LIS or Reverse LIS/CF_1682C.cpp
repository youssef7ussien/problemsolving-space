/**
 * Title: "LIS or Reverse LIS", Codeforces problem. 
 * Date: Sunday, 22 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second
#define INF                     1e9


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        map<int, int> freq;
        for(int i = 0 ; i < N ; i++) {
            CIN(num);
            freq[num]++;
        }

        int count1 = 0, count2 = 0;
        for(auto &it : freq)
            it.SS == 1 ? count1++ : count2++;

        cout<<(count2 + (count1 / 2 + count1 % 2))<<"\n";
    }
    
    return 0;
}