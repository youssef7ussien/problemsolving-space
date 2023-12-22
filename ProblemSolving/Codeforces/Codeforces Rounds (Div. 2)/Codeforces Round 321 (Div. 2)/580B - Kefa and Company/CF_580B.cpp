/**
 * Title: "Kefa and Company", Codeforces problem. 
 * Date: Tuesday, 15 March 2022 
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
typedef vector<PII>                 VII;


int main()
{
    FAST_IO;

    int N, D;
    cin>>N>>D;

    VII friends(N);
    for(auto &it : friends)
        cin>>it.first>>it.second;

    sort(ALL(friends));

    int left = N - 1, right = N - 1;
    Long result = 0, counter = 0;
    while(left >= 0) {
        if(friends[right].first - friends[left].first < D)
            counter += friends[left--].second;
        else
            result = max(result, counter), counter -= friends[right--].second;
    }
    
    cout<<max(result, counter)<<"\n";
    return 0;
}