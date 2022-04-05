/**
 * Title: "Count the Pairs", SPOJ - Sphere Online Judge problem. 
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


int main()
{
    FAST_IO;
    
    int N, K;
    cin>>N>>K;

    VI numbers(N);
    for(auto &it : numbers)
        cin>>it;

    sort(ALL(numbers));

    int counter = 0;
    for(int i = 0 ; i < SIZE(numbers) - 1 ; i++)
        counter += (*lower_bound(numbers.begin() + i + 1, numbers.end(), numbers[i] + K) - numbers[i] == K);
    
    cout<<counter<<"\n";
    return 0;
}