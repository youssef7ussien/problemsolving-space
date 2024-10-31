/**
 * Title: "Gifts Fixing", Codeforces problem. 
 * Date: Tuesday, 26 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     int(1e9 + 1)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI A(N), B(N);
        int minA = INF, minB = INF;
        for(auto &it : A) {
            cin>>it;
            minA = min(minA, it);
        }

        for(auto &it : B) {
            cin>>it;
            minB = min(minB, it);
        }

        Long counter = 0;
        for(int i = 0 ; i < N ; i++)
            if(A[i] - minA > 0 && B[i] - minB > 0)
                counter += min(A[i] - minA, B[i] - minB) + abs((A[i] - minA) - (B[i] - minB));
            else
                counter += (A[i] - minA) + (B[i] - minB);
                
        cout<<counter<<"\n";
    }
    
    return 0;
}