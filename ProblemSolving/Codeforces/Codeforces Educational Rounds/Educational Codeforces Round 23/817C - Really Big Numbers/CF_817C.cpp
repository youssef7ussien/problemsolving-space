/**
 * Title: "Really Big Numbers", Codeforces problem. 
 * Date: Thursday, 10 March 2022 
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


bool check(Long N, Long S) {
    Long sum = 0, temp = N;
    while(N > 0)
        sum += N % 10, N /= 10;

    return (temp - sum >= S);
}

Long binarySearch(Long N, Long S)
{
    Long left = 1, right = N;
    while(left <= right) {
        Long middle = left + (right - left) / 2;

        check(middle, S) ? right = middle - 1 : left = middle + 1;
    }

    return N - right;
}

int main()
{
    FAST_IO;
    
    Long N, S;
    cin>>N>>S;

    cout<<binarySearch(N, S)<<"\n";
    return 0;
}