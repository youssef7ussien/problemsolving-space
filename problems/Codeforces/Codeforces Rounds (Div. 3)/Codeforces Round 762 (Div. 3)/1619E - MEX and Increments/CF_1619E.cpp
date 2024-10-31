/**
 * Title: "MEX and Increments", Codeforces problem. 
 * Date: Wednesday, 04 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;
typedef vector<Long>            VL;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        VI freq(N + 1), wait;
        VL result(N + 1, -1);
        for(int i = 0 ; i < N ; i++) {
            CIN(temp);
            freq[temp]++;
        }
        
        Long lastSum = 0;
        for(int i = 0 ; i <= N ; i++) {
            if(i > 0 && freq[i - 1] == 0) {
                if(wait.empty())
                    break;

                lastSum += i - 1 - wait.back(), wait.pop_back();
            }

            result[i] = lastSum + freq[i];

            while(i > 0 && freq[i - 1] > 1)
                freq[i - 1]--, wait.push_back(i - 1);
        }

        for(auto &it : result)
          cout<<it<<" ";
        cout<<"\n";
    }

    return 0;
}