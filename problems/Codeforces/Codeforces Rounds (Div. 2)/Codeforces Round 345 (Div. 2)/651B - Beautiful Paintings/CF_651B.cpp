/**
 * Title: "Beautiful Paintings", Codeforces problem. 
 * Date: Tuesday, 09 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    int maxNum = 0;
    map<int, int> freq;
    for(int i = 0 ; i < N ; i++) {
        int num;
        cin>>num;
        maxNum = max(maxNum, ++freq[num]);
    }
        
    cout<<N - maxNum<<"\n";
    return 0;
}