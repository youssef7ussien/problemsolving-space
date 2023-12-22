/**
 * Title: "Word", Codeforces problem. 
 * Date: Wednesday, 18 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;

int main()
{
    string str;
    cin>>str;
    int countA = 0, countB = 0;

    for(auto &it : str) {
        if(isupper(it))
            countA++;
        else if(islower(it))
            countB++;
    }

    if(countA > countB)
        for(auto &it : str)
            cout<<char(toupper(it));
    else
        for(auto &it : str)
            cout<<char(tolower(it));
    return 0;
}