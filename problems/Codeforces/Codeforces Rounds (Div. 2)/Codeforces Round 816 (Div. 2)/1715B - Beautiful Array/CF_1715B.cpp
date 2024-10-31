/**
 * Title: "Beautiful Array", Codeforces problem. 
 * Date: Sunday, 21 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<Long>            VL;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int n, k, b;
        Long s;

        cin>>n>>k>>b>>s;

        if(s / k < b)
            { cout<<"-1\n"; continue; }
        
        VL arr(n);
        
        arr[0] = 1LL * b * k;
        s     -= 1LL * b * k;

        for(int i = 0 ; i < n ; i++) {
            arr[i] += min(1LL * k - 1, s);
            s      -= min(1LL * k - 1, s);
        }

        if(s > 0)
            { cout<<"-1\n"; continue; }

        for(auto &it : arr)
            cout<<it<<" ";
        cout<<"\n";
    }
    
    return 0;
}