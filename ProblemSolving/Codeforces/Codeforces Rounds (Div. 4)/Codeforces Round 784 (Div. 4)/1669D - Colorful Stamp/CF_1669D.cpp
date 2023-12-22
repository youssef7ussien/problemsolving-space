/**
 * Title: "Colorful Stamp", Codeforces problem. 
 * Date: Thursday, 21 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N; 
        string str;
        cin>>N>>str;
        
        vector<string> pictures;
        if(str[0] != 'W')
            pictures.push_back("");

        for(auto &it : str)
            if(it == 'W')
                pictures.push_back("");
            else
                pictures[SIZE(pictures) - 1] += it;

        bool can = true;
        for(auto &it : pictures)
            if(!it.empty() && !(it.find('R') != string::npos && it.find('B') != string::npos))
                { can = false; break; }

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}