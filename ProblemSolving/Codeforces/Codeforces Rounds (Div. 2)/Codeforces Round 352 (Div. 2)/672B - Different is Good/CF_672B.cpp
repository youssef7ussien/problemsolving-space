/**
 * Title: "Different is Good", Codeforces problem. 
 * Date: Friday, 24 June 2022 
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
    
    int N;
    string str;
    cin>>N>>str;

    if(N > 26)
        { cout<<"-1\n"; return 0; }

    VI freq(26);
    for(auto &it : str)
        freq[it - 'a']++;
    
    int counter = 0;
    for(auto &it : freq)
        counter += (it != 0 ? it - 1 : 0);
    
    cout<<counter<<"\n";
    return 0;
}