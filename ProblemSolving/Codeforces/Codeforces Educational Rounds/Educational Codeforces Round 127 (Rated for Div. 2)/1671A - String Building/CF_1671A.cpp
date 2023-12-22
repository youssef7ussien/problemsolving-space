/**
 * Title: "String Building", Codeforces problem. 
 * Date: Friday, 22 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<PII>             VII;


int main()
{   
    FAST_IO;
    
    TEST_CASES(T) {
        string str;
        cin>>str;

        bool can = true;
        for(int i = 0 ; i < SIZE(str) ;) {
            int count = 0;
            char temp = str[i];
            while(str[i] == temp && i < SIZE(str))
                count++, i++;

            if(count == 1)
                { can = false; break; }
        }

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}