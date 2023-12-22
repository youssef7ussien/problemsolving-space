/**
 * Title: "Odd-Even Increments", Codeforces problem. 
 * Date: Thursday, 21 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<PII>             VII;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        VI numbers(N);
        for(auto &it : numbers)
            cin>>it;
        bool can = true;
        
        if(numbers[0] % 2 == 0) {
            for(int i = 0 ; i < N ; i += 2)
                if (numbers[i] % 2 != 0)
                    can = false;
        }
        else {
            for(int i = 0 ; i < N ; i += 2)
                if (numbers[i] % 2 == 0)
                    can = false;
        }

        if (numbers[1] % 2 == 0) {
            for(int i = 1 ; i < N ; i += 2)
                if (numbers[i] % 2 != 0)
                    can = false;
        }
        else {
            for(int i = 1 ; i < N ; i += 2)
                if (numbers[i] % 2 == 0)
                    can = false;
        }

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}