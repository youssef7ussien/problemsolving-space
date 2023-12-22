/**
 * Title: "Dictionary", Codeforces problem. 
 * Date: Tuesday, 03 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    map<string, int> dict;
    int count = 1;
    for(char i = 'a' ; i <= 'z' ; i++) {
        for(char j = 'a' ; j <= 'z' ; j++)
            if(i != j) {
                string str ={i, j};
                dict[str] = count++;
            }
    }

    TEST_CASES(T) {
        string str;
        cin>>str;

        cout<<dict[str]<<"\n";
    }
    
    return 0;
}