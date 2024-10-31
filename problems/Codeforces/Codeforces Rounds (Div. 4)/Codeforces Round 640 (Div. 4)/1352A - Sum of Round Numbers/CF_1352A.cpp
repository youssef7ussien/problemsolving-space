/**
 * Title: "Sum of Round Numbers", Codeforces problem. 
 * Date: Wednesday, 20 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        string str;
        cin>>str;

        VI result;
        for(int i = SIZE(str) - 1, power = 1 ; i >= 0 ; i--, power *= 10)
            if(str[i] != '0')
                result.push_back(int(str[i] - '0') * power);

        cout<<SIZE(result)<<"\n";
        for(auto &it : result)
            cout<<it<<" ";
        cout<<"\n";
    }
    
    return 0;
}