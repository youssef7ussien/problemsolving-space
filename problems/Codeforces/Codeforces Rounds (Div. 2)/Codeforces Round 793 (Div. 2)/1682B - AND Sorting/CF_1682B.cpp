/**
 * Title: "AND Sorting", Codeforces problem. 
 * Date: Sunday, 22 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
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
        
        VI arr;
        for(int i = 0 ; i < N ; i++) {
            CIN(num);
            if(num != i)
                arr.push_back(num);
        }

        Long result = arr[0];
        for(int i = 1 ; i < LEN(arr) ; i++)
            result &= arr[i];
        
        cout<<result<<"\n";
    }
    
    return 0;
}