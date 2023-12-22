/**
 * Title: "Make It Increasing", Codeforces problem. 
 * Date: Friday, 06 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        Long counter = 0;
        VI numbers(N);
        for(auto &it : numbers)
            cin>>it;
        
        for(int i = N - 2 ; i >= 0 ; i--) {
            while(numbers[i] >= numbers[i + 1] && numbers[i] > 0)
                counter++, numbers[i] /= 2;
            
            if(numbers[i] == numbers[i + 1]) 
                { counter = -1; break; }
        }

        cout<<counter<<"\n";
    }
    
    return 0;
}