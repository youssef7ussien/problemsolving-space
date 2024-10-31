/**
 * Title: "Wrong Addition", Codeforces problem. 
 * Date: Monday, 20 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long         Long;


int main()
{
    FAST_IO;
    
    TEST_CASES(T)
    {
        Long A, S;
        string B;

        cin>>A>>S;

        while(S > 0) {
            int digitA = A % 10;
            int digitS = S % 10;
            int newDigit = (10 + digitS - digitA) % 10;

            if(digitA + newDigit == digitS)
                B = to_string(newDigit) + B, A /= 10, S /= 10;
            else if(digitA + newDigit == S % 100)
                B = to_string(newDigit) + B, A /= 10, S /= 100;
            else
                break;
        }

        if(A != 0)
            cout<<"-1\n";
        else
            cout<<B.erase(0, B.find_first_not_of('0'))<<"\n";
    }
    
    return 0;
}