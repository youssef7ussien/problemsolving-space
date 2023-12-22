/**
 * Title: "Pupils Redistribution", Codeforces problem. 
 * Date: Saturday, 25 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    map<int, int> freq;
    for(int i = 0 ; i < N ; i++) {
        CIN(num);
        freq[num]++;
    }

    for(int i = 0 ; i < N ; i++) {
        CIN(num);
        freq[num]--;
    }

    int counter = 0;
    for(auto &it : freq) {
        if(it.second % 2 != 0)
            { counter = -1; break; }
        else
            counter += abs(it.second) / 2;
    }
    
    cout<<(counter == -1 ? -1 : counter / 2)<<"\n";
    return 0;
}