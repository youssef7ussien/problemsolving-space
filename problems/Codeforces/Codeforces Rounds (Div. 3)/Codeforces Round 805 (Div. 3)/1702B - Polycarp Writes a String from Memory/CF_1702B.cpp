/**
 * Title: "Polycarp Writes a String from Memory", Codeforces problem. 
 * Date: Saturday, 06 August 2022 
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
        string str;
        cin>>str;

        int counter = 0;
        map<char, int> freq;
        for(auto &it : str) {
            freq[it]++;
            if(LEN(freq) > 3)
                counter++, freq.clear(), freq[it]++;
        }

        cout<<counter + (LEN(freq) != 0)<<"\n";
    }
    
    return 0;
}