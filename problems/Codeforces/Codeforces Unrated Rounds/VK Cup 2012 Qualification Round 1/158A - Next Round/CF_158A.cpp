/**
 * Title: "Next Round", Codeforces problem. 
 * Date: Friday, 18 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                 ((v).begin()), ((v).end())
#define FAST_IO                ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                    1e9

typedef long long              Long;
typedef pair<int, int>         PII;
typedef vector<int>            VI;


int main()
{   
    FAST_IO;
    
    int N, K;
    cin>>N>>K;

    VI numbers(N);
    for(auto &it : numbers)
        cin>>it;
    
    int counter = 0;
    for(int i = 0 ; i<N ; i++)
        counter += (numbers[i] >= numbers[K-1] && numbers[i] > 0);
    
    cout<<counter<<"\n";
    return 0;
}