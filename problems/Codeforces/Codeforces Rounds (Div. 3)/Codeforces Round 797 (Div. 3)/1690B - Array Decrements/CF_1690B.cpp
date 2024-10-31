/**
 * Title: "Array Decrements", Codeforces problem. 
 * Date: Thursday, 09 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI arrA(N), arrB(N);
        for(auto &it : arrA)
            cin>>it;

        int maxDiff = -INF;
        for(int i = 0 ; i < N ; i++) {
            cin>>arrB[i];
            maxDiff = max(maxDiff, arrA[i] - arrB[i]);
        }

        if(maxDiff < 0)
            cout<<"NO\n";
        else {
            for(int i = 0 ; i < N ; i++)
                arrA[i] = max(0, arrA[i] - maxDiff);
            cout<<(arrA == arrB ? "YES" : "NO")<<"\n";
        }
    }
    
    return 0;
}