/**
 * Title: "Ternary String", Codeforces problem. 
 * Date: Monday, 07 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;
typedef vector<PII>                 VII;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        string str;
        cin>>str;

        if(SIZE(str) < 3) {
            cout<<0<<"\n";
            continue;
        }

        unordered_map<char, int> freq;
        for(int i = 0 ; i < 3 ; i++)
            freq[str[i]]++;

        int result = (freq['1'] && freq['2'] && freq['3'] ? min(int(INF), 3) : INF);

        for(int i = 0, j = 3 ; j < SIZE(str) ; j++) {
            freq[str[j]]++;
            
            while(freq[str[i]] > 1) 
                freq[str[i++]]--;

            if(freq['1'] && freq['2'] && freq['3'])
                result = min(result, j - i + 1);
        }

        cout<<(result == INF ? 0 : result)<<"\n";
    }
    
    return 0;
}