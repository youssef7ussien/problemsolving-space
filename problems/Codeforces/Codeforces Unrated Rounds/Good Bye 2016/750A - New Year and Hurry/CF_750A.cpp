/**
 * Title: "New Year and Hurry", Codeforces problem. 
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
typedef vector<int>                 VI;


int main()
{
    FAST_IO;
    
    int N, K, counter = 1;
    cin>>N>>K;

    while((counter * (counter + 1) / 2) * 5 <= 240 - K && counter <= N)
        counter++;
    
    cout<<counter - 1<<"\n";
    
    return 0;
}