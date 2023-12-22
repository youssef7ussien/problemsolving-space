/**
 * Title: "Train and Queries", Codeforces problem. 
 * Date: Saturday, 06 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, K;
        cin>>N>>K;
        
        map<int, pair<int, int>> pos;
        for(int i = 1 ; i <= N ; i++) {
            int num;
            cin>>num;
            
            if(pos.count(num) == 0)
                pos[num] = {i, i};
            else
                pos[num].SS = i;
        }

        while(K--) {
            int start, end;
            cin>>start>>end;

            cout<<(pos.count(start) && pos.count(end) && pos[start].FF <= pos[end].SS ? "YES" : "NO")<<"\n";
        }
    }
    
    return 0;
}