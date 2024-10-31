/**
 * Title: "Binary Deque", Codeforces problem. 
 * Date: Tuesday, 14 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     int(1e9 + 5)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, S;
        cin>>N>>S;
        
        VI prefix(N + 1);
        for(int i = 1 ; i <= N ; i++) {
            CIN(num);
            prefix[i] = num + prefix[i - 1];
        }

        if(prefix.back() < S) 
            { cout<<"-1\n"; continue; }
        if(prefix.back() == S) 
            { cout<<"0\n"; continue; }

        int left = 0, right = 0, counter = INF;
        while(++right <= N) {
            if(prefix[right] - prefix[left] < S)
                continue;
            else if(prefix[right] - prefix[left] == S)
                counter = min(counter, N - (right - left));
            
            while(prefix[right] - prefix[left] > S)
                left++;
        }

        cout<<counter<<"\n";
    }
    
    return 0;
}