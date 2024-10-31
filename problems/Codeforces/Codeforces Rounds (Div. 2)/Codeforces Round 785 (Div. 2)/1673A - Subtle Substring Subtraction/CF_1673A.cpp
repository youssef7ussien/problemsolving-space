/**
 * Title: "Subtle Substring Subtraction", Codeforces problem. 
 * Date: Sunday, 01 May 2022 
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

        int sum = 0;
        for(int i = 0 ; i < SIZE(str) ; i++)
            sum += str[i] - 'a' + 1;

        if(SIZE(str) % 2 == 0)
            cout<<"Alice "<<sum<<"\n";
        else if(SIZE(str) % 2 != 0 && SIZE(str) != 1)
            cout<<"Alice "<<sum - min(str[0] - 'a' + 1, str.back() - 'a' + 1) * 2<<"\n";
        else
            cout<<"Bob "<<sum<<"\n";
    }
    
    return 0;
}