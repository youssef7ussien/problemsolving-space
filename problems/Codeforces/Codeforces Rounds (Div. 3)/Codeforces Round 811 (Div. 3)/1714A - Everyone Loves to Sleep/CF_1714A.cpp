/**
 * Title: "Everyone Loves to Sleep", Codeforces problem. 
 * Date: Monday, 01 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second
#define INF                     1e9
typedef pair<int, int>          PII;


PII diffTime(PII t1, PII t2) {
    PII result = {(t2.FF - t1.FF + 24) % 24, 0};

    if(t2.SS - t1.SS < 0)
        result = {(result.FF - 1 + 24) % 24, 60 - (t1.SS - t2.SS)};
    else
        result.SS = (t2.SS - t1.SS + 60) % 60;
    
    return result;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, H, M;
        cin>>N>>H>>M;
            
        PII result = {INF, INF};
        for(int i = 0 ; i < N ; i++) {
            PII it;
            cin>>it.FF>>it.SS;

            result = min(diffTime({H, M}, it), result);
        }
        
        cout<<result.FF<<" "<<result.SS<<"\n";
    }
    
    return 0;
}