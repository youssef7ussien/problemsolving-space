/**
 * Title: "Wrong Addition", Codeforces problem. 
 * Date: Monday, 20 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF               1e18
#define TO_INT(ch)        int(ch - '0')
typedef long long         Long;


int main()
{
    FAST_IO;
    
    TEST_CASES(T)
    {
        string A, S, B = "";
        deque<int> numbers;
        cin>>A>>S;

        int i = SIZE(A) - 1, j = SIZE(S) - 1;

        for(; i >= 0 && j >= 0 ; i--, j--) {
            if(A[i] > S[j])
                numbers.push_front(TO_INT(S[j - 1]) * 10 + TO_INT(S[j]) - TO_INT(A[i])), j--;
            else
                numbers.push_front(TO_INT(S[j]) - TO_INT(A[i]));
        }

        if(j == -1 && i > -1)
            { cout<<"-1\n"; continue; }

        while(j > -1)
            numbers.push_front(TO_INT(S[j--]));

        bool valid = true;
        j = SIZE(numbers) - 1, i = SIZE(A) - 1;

        for(; i >= 0 && j >= 0 ; i--, j--) {
            if(numbers[j] > 9)
                { valid = false; break; }

            B.insert(0, to_string(TO_INT(A[i]) + numbers[j]));
        }

        if(!valid)
            { cout<<"-1"<<"\n"; continue; }

        while(j > -1)
            B.insert(0, to_string(numbers[j--]));
        
        if(B == S) {
            bool leading = true;
            for(auto &it : numbers)
                if((leading && it != 0) || !leading)
                    cout<<it, leading = false;
            cout<<"\n";
        }
        else
            cout<<"-1"<<"\n";
    }
    
    return 0;
}