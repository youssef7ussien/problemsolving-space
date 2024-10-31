/**
 * Title: "Prof. Slim", Codeforces problem. 
 * Date: Friday, 06 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI numbers(N);
        int countNeg = 0;

        for(int i = 0 ; i < N ; i++) {
            cin>>numbers[i];
            countNeg += (numbers[i] < 0);
        }

        for(int i = 0 ; i < N ; i++)
            numbers[i] = (i >= countNeg ? abs(numbers[i]) : -abs(numbers[i]));

        cout<<(is_sorted(ALL(numbers)) ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}