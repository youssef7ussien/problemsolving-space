/**
 * Title: "All Distinct", Codeforces problem. 
 * Date: Tuesday, 14 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef pair<int, int>          PII;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        set<int> arr;
        for(int i = 0 ; i < N ; i++) {
            CIN(num);
            arr.insert(num);
        }

        cout<<(N % 2 == LEN(arr) % 2 ? LEN(arr) : LEN(arr) - 1)<<"\n";
    }
    
    return 0;
}