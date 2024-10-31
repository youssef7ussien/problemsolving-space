/**
 * Title: "2-Letter Strings", Codeforces problem. 
 * Date: Thursday, 21 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;


int main()
{   
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        Long counter = 0;
        map<pair<char, char>, int> freq;

        while(N--) {
            string str;
            cin>>str;
            for(char ch = 'a' ; ch <= 'k' ; ch++)
                if(ch != str[0])
                    counter += freq[{ch, str[1]}];

            for(char ch = 'a' ; ch <= 'k' ; ch++)
                if(ch != str[1])
                    counter += freq[{str[0], ch}];

            freq[{str[0], str[1]}]++;
        }
        
        cout<<counter<<"\n";
    }
    
    return 0;
}