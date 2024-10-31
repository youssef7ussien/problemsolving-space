/**
 * Title: "Longest Strike", Codeforces problem. 
 * Date: Tuesday, 10 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, K;
        cin>>N>>K;
        
        VI arr(N), counts;
        map<int, int> freq;
        
        for(auto &it : arr) {
            cin>>it;
            freq[it]++;
        }

        for(auto &it : freq)
            if(it.second >= K)
                counts.push_back(it.first);
        
        if(counts.empty())
            { cout<<-1<<"\n"; continue; }

        sort(ALL(counts));

        int left = counts[0], right = counts[0], maxDiff = 0, last = counts[0];
        for(int i = 1 ; i < LEN(counts) ; i++) {
            if(counts[i] == counts[i - 1] + 1) {
                if(maxDiff < counts[i] - last)
                    left = last, right = counts[i], maxDiff = counts[i] - last;
            }
            else
                last = counts[i];
        }

        cout<<left<<" "<<right<<"\n";
    }
    
    return 0;
}