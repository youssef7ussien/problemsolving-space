/**
 * Title: "Boxes Packing", Codeforces problem. 
 * Date: Tuesday, 28 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    int result = 0;
    map<int, int> freq;
    for(int i = 0 ; i < N ; i++) {
        CIN(num);
        result = max(result, ++freq[num]);
    }
        
    cout<<result<<"\n";
    return 0;
}