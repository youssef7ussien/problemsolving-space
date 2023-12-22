/**
 * Title: "DIV + MOD", Codeforces problem. 
 * Date: Tuesday, 08 March 2022 
 *
 */

/**
 * this table for numbers from 1 to 29 and result of F(x, a) when a = 3
 * ------------------------------
 *    period             F(x, a)
 *  0 (1,   2) --------> 1  2
 *  1 (3,   5) --------> 1  2 3
 *  2 (6,   8) --------> 2  3 4
 *  3 (9,  11) --------> 3  4 5
 *  4 (12, 14) --------> 4  5 6
 *  5 (15, 17) --------> 5  6 7
 *  6 (18, 20) --------> 6  7 8
 *  7 (21, 23) --------> 7  8 9
 *  8 (24, 26) --------> 8  9 10
 *  9 (27, 29) --------> 9 10 11
 * ------------------------------
 * 
 * So when we need max F(x, a):
 *      1. We are looking for the last number in the period before a R period by (R / A) * A - 1
 *      2. Get max between it and L (to check if it in range or not).
 *      3. Get max between F(L, A) and F(R, A).
 * 
 * Ex: 23 27 3
 *      1. (R / A) * A - 1 = 26
 *      2. max(26, 23) = 26
 *      3. max(F(26, 3), F(27, 3)) = max(10, 9) = 10
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9                       

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;
typedef vector<PII>                 VII;

inline int F(int X, int A) {
    return (X/A + X % A);
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int L, R, A;
        cin>>L>>R>>A;

        cout<<max(F(max((R / A) * A - 1, L), A), F(R, A))<<"\n";
    }
    
    return 0;
}