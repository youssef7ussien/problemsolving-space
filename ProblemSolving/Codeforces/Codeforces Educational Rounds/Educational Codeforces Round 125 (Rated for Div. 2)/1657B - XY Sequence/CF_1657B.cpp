/**
 * Title: "XY Sequence", Codeforces problem. 
 * Date: Saturday, 26 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)        int T; cin>>T; while(T--)
#define FAST_IO              ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long            Long;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, B, x, y;
        cin>>N>>B>>x>>y;

        Long current = 0, result = 0;
        for(int i = 1 ; i <= N ; i++)
            current += (current + x <= B ? x : -y), result += current;
        
        cout<<result<<"\n";
    }
    
    return 0;
}