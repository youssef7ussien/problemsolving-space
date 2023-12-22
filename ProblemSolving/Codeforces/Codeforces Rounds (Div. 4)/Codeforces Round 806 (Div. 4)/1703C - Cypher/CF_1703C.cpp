/**
 * Title: "Cypher", Codeforces problem. 
 * Date: Thursday, 21 July 2022 
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
        
        for(int i = 0 ;  i < N ; i++) {
            int num; cin>>num;
            
            while(num--) {
                char ch; cin>>ch;

                if(ch == 'D')
                    arr[i] = (arr[i] + 1) % 10;
                else if(ch == 'U')
                    arr[i] = (arr[i] + 9) % 10;
            }
        }

        for(auto &it : arr)
          cout<<it<<" ";
        cout<<"\n";
    }
    
    return 0;
}