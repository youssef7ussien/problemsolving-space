/**
 * Title: "Remove Prefix", Codeforces problem. 
 * Date: Monday, 01 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
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
        
        int counter = N;
        map<int, int> freq;

        for(int i = N - 1 ; i >= 0 ; i--)
            if(++freq[arr[i]] <= 1)
                counter--;
            else
                break;

        cout<<counter<<"\n";
    }
    
    return 0;
}