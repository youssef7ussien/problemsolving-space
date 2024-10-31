/**
 * Title: "Word Game", Codeforces problem. 
 * Date: Tuesday, 30 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        map<string, std::array<bool, 3>> freq;
        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < N ; j++) {
                string str; cin>>str;
                
                freq[str][i] = true;
            }
        
        int count[3] = {0, 0, 0};
        for(auto &it : freq) {
            if(it.second[0] + it.second[1] + it.second[2] == 3)
                continue;
            if(it.second[0] + it.second[1] + it.second[2] > 1)
                count[0] += it.second[0], 
                count[1] += it.second[1], 
                count[2] += it.second[2];
            else
                count[0] += (it.second[0] ? 3 : 0), 
                count[1] += (it.second[1] ? 3 : 0), 
                count[2] += (it.second[2] ? 3 : 0);
        }

        for(int i = 0 ; i < 3 ; i++)
            cout<<count[i]<<" ";
        cout<<"\n";
    }
    
    return 0;
}