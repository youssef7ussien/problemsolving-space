/**
 * Title: "Getting Zero", Codeforces problem. 
 * Date: Sunday, 10 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        CIN(num);

        if(num == 0) 
            { cout<<0<<"\n"; continue; }
        
        int result = 15; // 32768 == 2^15
        for(int i = 0 ; i < 15 ; i++) {
            int temp = num + i, counter = 0;
            while(temp % 32768 != 0)
                counter++, temp *= 2;

            result = min(result, i + counter);
        }
        
        cout<<result<<" ";
    }
    
    return 0;
}