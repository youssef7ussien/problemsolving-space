/**
 * Title: "Make it Increasing", Codeforces problem. 
 * Date: Thursday, 02 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;
#define INF                     Long(1e18 + 5)
typedef vector<int>             VI;
typedef vector<Long>            VL;


int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    VI arrA(N);
    for(auto &it : arrA)
        cin>>it;

    Long result = INF;
    for(int i = 0 ; i < N ; i++) {
        Long moves = 0;
        VL arrB(N);

        for(int j = i - 1 ; j >= 0 ; j--) {
            moves += arrB[j + 1] / arrA[j] + 1;
            arrB[j] = (arrB[j + 1] / arrA[j] + 1) * arrA[j];
        }

        for(int j = i + 1 ; j < N ; j++) {
            moves += arrB[j - 1] / arrA[j] + 1;
            arrB[j] = (arrB[j - 1] / arrA[j] + 1) * arrA[j];
        }

        result = min(result, moves);
    }
    
    cout<<result<<"\n";
    return 0;
}