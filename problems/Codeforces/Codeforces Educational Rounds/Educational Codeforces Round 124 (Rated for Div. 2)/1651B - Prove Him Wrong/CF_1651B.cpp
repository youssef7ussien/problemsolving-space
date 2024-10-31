/**
 * Title: "Prove Him Wrong", Codeforces problem. 
 * Date: Thursday, 10 March 2022 
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
        int N;
        cin>>N;

        bool found = true;
        VI numbers(1, 1);
        for(int i = 1 ; i < N ; i++) {
            if((Long)numbers[i - 1] * 3 > INF)
                { found = false; break; }

            numbers.push_back(numbers[i - 1] * 3);
        }
        
        if(found) {
            cout<<"YES"<<"\n";
            for(auto &it : numbers)
                cout<<it<<" ";
            cout<<"\n";
        }
        else
            cout<<"NO"<<"\n";
    }
    
    return 0;
}