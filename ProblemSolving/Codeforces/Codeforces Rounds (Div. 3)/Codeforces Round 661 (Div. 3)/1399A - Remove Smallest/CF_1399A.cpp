/**
 * Title: "Remove Smallest", Codeforces problem. 
 * Date: Tuesday, 26 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI numbers(N);
        for(auto &it : numbers)
            cin>>it;
        sort(ALL(numbers));

        bool can = true;
        for(int i = 0 ; i < N - 1 ; i++)
            if(numbers[i + 1] - numbers[i] > 1)
                { can = false; break; }
        
        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}