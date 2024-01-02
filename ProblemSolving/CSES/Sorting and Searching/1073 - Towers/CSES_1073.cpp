/**
 * Title: "Towers", CSES problem. 
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

int main()
{
    FAST_IO;
    
    multiset<int> tower;
    TEST_CASES(T) {
        int temp; cin>>temp;

        auto it = tower.upper_bound(temp);
        if(it == tower.end())
            tower.insert(temp);
        else
            tower.erase(it), tower.insert(temp);
    }

    cout<<tower.size()<<"\n";
    return 0;
}