/**
 * Title: "Unique Number", Codeforces problem. 
 * Date: Sunday, 05 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int X;
        cin>>X;

        if(X > 45)
            {cout<<-1<<"\n"; continue; }

        string result;
        for(int i = 9 ; i >= 1 ; i--) {
            if(X <= 9 && X <= i) 
                { result += X + '0'; break; }
            
            result += i + '0', X -= i;
        }
        
        reverse(ALL(result));
        cout<<result<<"\n";
    }
    
    return 0;
}