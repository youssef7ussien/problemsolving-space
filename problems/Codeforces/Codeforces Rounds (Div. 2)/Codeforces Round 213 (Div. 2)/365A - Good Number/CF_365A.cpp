/**
 * Title: "Good Number", Codeforces problem. 
 * Date: Wednesday, 02 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;


int main()
{
    FAST_IO;
    
    int N, K, counter = 0;
    cin>>N>>K;

    while(N--) {
        set<char> numbers;
        string str; cin>>str;
        
        for(const auto &it : str)
            if((it - '0') % 10  <= K)
                numbers.insert(it);

        counter += (SIZE(numbers) == K+1);
    }

    cout<<counter<<"\n";
    return 0;
}