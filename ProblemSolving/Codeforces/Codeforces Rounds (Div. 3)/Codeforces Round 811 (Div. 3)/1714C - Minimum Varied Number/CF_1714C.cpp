/**
 * Title: "Minimum Varied Number", Codeforces problem. 
 * Date: Monday, 01 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int s;
        cin>>s;

        deque<int> result;
        int digit = 9;
        
        while(s) {
            while(s < digit) digit--;

            s -= digit;
            result.push_front(digit--);
        }
        
        for(auto &it : result)
            cout<<it;
        cout<<"\n";
    }
    
    return 0;
}