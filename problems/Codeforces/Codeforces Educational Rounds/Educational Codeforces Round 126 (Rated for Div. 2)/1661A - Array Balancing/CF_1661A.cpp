/**
 * Title: "Array Balancing", Codeforces problem. 
 * Date: Saturday, 09 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        VI arrA(N), arrB(N);
        for(auto &it : arrA) cin>>it;
        for(auto &it : arrB) cin>>it;

        Long result = 0;
        for(int i = 0 ;  i < N - 1 ; i++)
                result += min(abs(arrA[i] - arrA[i + 1]) + abs(arrB[i] - arrB[i + 1]),
                        abs(arrA[i] - arrB[i + 1]) + abs(arrA[i + 1] - arrB[i])
                    );

        cout<<result<<"\n";
    }
    
    return 0;
}