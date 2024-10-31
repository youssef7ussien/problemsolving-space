/**
 * Title: "Round Down the Price", Codeforces problem. 
 * Date: Friday, 05 August 2022 
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
        int num;
        cin>>num;

        cout<<(num - stoi("1" + string(LEN(to_string(num)) - 1, '0')))<<"\n";
    }
    
    return 0;
}