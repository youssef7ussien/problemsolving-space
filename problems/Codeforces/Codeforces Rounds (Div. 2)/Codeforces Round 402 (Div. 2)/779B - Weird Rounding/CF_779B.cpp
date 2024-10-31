/**
 * Title: "Weird Rounding", Codeforces problem. 
 * Date: Saturday, 25 June 2022 
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
    
    string N;
    int K;
    cin>>N>>K;

    if(LEN(N) <= K)
        { cout<<LEN(N) - 1<<"\n"; return 0; }
    
    int zeros = 0, nonzeros = 0;
    for(int i = LEN(N) - 1 ; i >= 0 ; i--) {
        if(N[i] == '0') {
            if(++zeros == K)
                break;
        }
        else
            nonzeros++;
    }
    
    cout<<(zeros == K ? nonzeros : LEN(N) - 1)<<"\n";
    return 0;
}