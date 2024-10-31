/**
 * Title: "Multiplication Table", Codeforces problem. 
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


bool check(Long N, Long M, Long K, Long middle)
{
    Long counter = 0;
    middle--;
    for(int i = 1 ; i <= N ; i++)
        counter += min(middle / i, M);

    return counter < K;
}

Long binarySearch(Long N, Long M, Long K)
{
    Long left = 1, right = N * M, result = 0;

    while(left <= right) {
        Long middle = (left + right) / 2;
        if(check(N, M, K, middle))
            left = middle + 1, result = middle;
        else
            right = middle - 1;
    }

    return result;
}

int main()
{
    FAST_IO;
    
    Long N, M, K;
    cin>>N>>M>>K;

    cout<<binarySearch(N, M, K)<<"\n";
    return 0;
}