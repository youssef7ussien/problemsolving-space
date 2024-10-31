/**
 * Title: "Detective Task", Codeforces problem. 
 * Date: Friday, 06 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        string str;
        cin>>str;

        if(SIZE(str) == 1) {
            cout<<1<<"\n";
            continue;
        }
        int first0 = (int)str.find_first_of('0');
        first0 = (first0 == (int)string::npos ? SIZE(str) - 1 : first0);
        
        cout<<first0 - max((int)str.find_last_of('1'), 0) + 1<<"\n";
    }
    
    return 0;
}