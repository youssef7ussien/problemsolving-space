/**
 * Title: "Yet Another Tetris Problem", Codeforces problem. 
 * Date: Wednesday, 29 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, num, flag;
        cin>>N>>num;

        flag = num % 2;
        bool can = true;
        for(int i = 1 ; i < N ; i++) {
            cin>>num;

            if(num % 2 != flag)
                can = false;
        }

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}