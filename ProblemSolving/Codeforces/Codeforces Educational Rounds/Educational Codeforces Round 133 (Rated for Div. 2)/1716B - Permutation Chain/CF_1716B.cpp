/**
 * Title: "Permutation Chain", Codeforces problem. 
 * Date: Thursday, 04 August 2022 
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
        for(int i = 0 ; i < N ; i++)
            arr[i] = i + 1;
        
        cout<<N<<"\n";
        for(int i = 0 ; i < N ; i++) {
            swap(arr[0], arr[i]);
            
            for(auto &it : arr)
              cout<<it<<" ";
            cout<<"\n";
        }
    }
    
    return 0;
}