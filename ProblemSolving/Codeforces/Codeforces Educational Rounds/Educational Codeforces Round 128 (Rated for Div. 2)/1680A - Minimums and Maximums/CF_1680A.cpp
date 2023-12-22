/**
 * Title: "Minimums and Maximums", Codeforces problem. 
 * Date: Friday, 13 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        PII g1, g2;
        cin>>g1.FF>>g1.SS>>g2.FF>>g2.SS;

        if(g1.FF == g2.FF)
            cout<<g1.FF<<"\n";
        else
            cout<<(max(g1.FF, g2.FF) > min(g1.SS, g2.SS) ? g1.FF + g2.FF : max(g1.FF, g2.FF))<<"\n";
    }
    
    return 0;
}