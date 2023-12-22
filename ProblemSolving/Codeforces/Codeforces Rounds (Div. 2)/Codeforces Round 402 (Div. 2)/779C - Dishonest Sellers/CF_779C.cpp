/**
 * Title: "Dishonest Sellers", Codeforces problem. 
 * Date: Saturday, 25 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<PII>             VII;


int main()
{
    FAST_IO;
    
    int N, K;
    cin>>N>>K;
    
    VI arrA(N), arrB(N);
    VII diff(N);
    
    for(auto &it : arrA)
        cin>>it;

    for(int i = 0 ; i < N ; i++) {
        cin>>arrB[i];
        diff[i] = {arrA[i] - arrB[i], i};
    }

    sort(ALL(diff));

    Long counter = 0;
    for(int i = 0 ; i < K ; i++)
        counter += arrA[diff[i].second];
    
    for(int i = K ; i < N ; i++)
        counter += min(arrA[diff[i].second], arrB[diff[i].second]);
    
    cout<<counter<<"\n";
    return 0;
}