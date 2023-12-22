/**
 * Title: "Watchmen", Codeforces problem. 
 * Date: Tuesday, 09 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second
typedef long long               Long;
typedef pair<int, int>          PII;


int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    map<PII, int> freq;
    map<int, int> freqX, freqY;

    for(int i = 0 ; i < N ; i++) {
        int x, y;
        cin>>x>>y;

        freqX[x]++, freqY[y]++, freq[{x, y}]++;
    }
    
    Long counter = 0;
    for(auto &it : freqX)
        counter += 1LL * it.SS * (it.SS - 1) / 2;
    
    for(auto &it : freqY)
        counter += 1LL * it.SS * (it.SS - 1) / 2;
    
    for(auto &it : freq)
        counter -= 1LL * it.SS * (it.SS - 1) / 2;
    
    cout<<counter<<"\n";
    return 0;
}