/**
 * Title: "NIT Destroys the Universe", Codeforces problem. 
 * Date: Saturday, 25 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI arr(N);
        for(auto &it : arr)
            cin>>it;
        
        int zeros = (arr[0] != 0);
        for(int i = 0 ; i < N - 1 ; i++)
            if(arr[i] == 0 && arr[i + 1] != 0)
                zeros++;
        
        cout<<min(2, zeros)<<"\n";
    }
    
    return 0;
}