/**
 * Title: "Favorite Sequence", Codeforces problem. 
 * Date: Friday, 11 March 2022 
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

        VI numbers(N), result(N);
        for(auto &it : numbers)
            cin>>it;

        int left = 0, right = N - 1;
        for(int i = 0 ; i < N ; i++) {
            result[i] = numbers[(i%2 == 0 ? left++ : right--)];
        }

        for(auto &it : result)
            cout<<it<<" ";
        cout<<"\n";
    }

    return 0;
}