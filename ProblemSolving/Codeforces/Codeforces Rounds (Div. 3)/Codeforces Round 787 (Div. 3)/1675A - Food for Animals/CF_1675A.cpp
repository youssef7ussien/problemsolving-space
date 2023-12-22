/**
 * Title: "Food for Animals", Codeforces problem. 
 * Date: Friday, 06 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9
typedef long long               Long;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int A, B, C, X, Y;
        cin>>A>>B>>C>>X>>Y;
        
        cout<<((max(X - A, Y - B) <= C &&  A + B + C >= Y + X) ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}