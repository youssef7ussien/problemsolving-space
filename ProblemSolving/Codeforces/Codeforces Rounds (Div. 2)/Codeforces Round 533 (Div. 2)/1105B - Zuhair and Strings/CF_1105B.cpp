/**
 * Title: "Zuhair and Strings", Codeforces problem. 
 * Date: Saturday, 02 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef pair<int, int>          PII;


int main()
{
    FAST_IO;
    
    int K;
    string str;
    
    cin>>K>>K>>str;

    int result = 0;
    for(char ch = 'a' ; ch <= 'z' ; ch++) {
        PII counter = {0, 0};
        for(auto &it : str) {
            counter.first = (it == ch ? counter.first + 1 : 0);

            if(counter.first == K)
                counter.second++, counter.first = 0;
        }

        result = max(result, counter.second);
    }

    cout<<result<<"\n";
    return 0;
}