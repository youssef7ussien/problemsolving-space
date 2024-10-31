/**
 * Title: "Ordinary Numbers", Codeforces problem. 
 * Date: Tuesday, 03 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;


int main()
{    
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        Long counter = 0;
        for (int i = 1 ; i <= 9 ; i++) {
            Long j = i;
            while(j <= N)
                counter++, j = j * 10 + i;
        }

        cout<<counter<<"\n";
        
    }
    
    return 0;
}