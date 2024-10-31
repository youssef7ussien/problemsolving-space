/**
 * Title: "YES or YES", Codeforces problem. 
 * Date: Thursday, 21 July 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)



int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        string str;
        cin>>N>>str;

        map<char, int> freq;
        for(auto &it : str)
            freq[it]++;
        
        int counter = LEN(freq);
        for(auto &it : freq)
            counter += it.second;
        
        cout<<counter<<"\n";
    }
    
    return 0;
}