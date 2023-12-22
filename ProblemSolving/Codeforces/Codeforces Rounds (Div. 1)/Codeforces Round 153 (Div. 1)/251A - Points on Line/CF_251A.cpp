/**
 * Title: "Points on Line", Codeforces problem. 
 * Date: Wednesday, 02 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)               freopen(file, "r", stdin)
#define FILE_OUT(file)              freopen(file, "w", stdout)
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;


int main()
{
    #ifdef __DEBUG
        FILE_IN("samples\\__CF_251A.in");
        FILE_OUT("samples\\__CF_251A.out");
    #endif

    FAST_IO;
    
    int N, D;
    cin>>N>>D;
    
    VI numbers(N);
    for(auto &it : numbers)
        cin>>it;
    
    Long counter = 0;
    for(int i = 0 ; i < SIZE(numbers) - 2 ; i++) {
        Long index = upper_bound(numbers.begin() + i + 1, numbers.end(), numbers[i] + D) - numbers.begin() - i - 1;
        counter += index * (index - 1) / 2;
    }

    cout<<counter<<"\n";
    return 0;
}