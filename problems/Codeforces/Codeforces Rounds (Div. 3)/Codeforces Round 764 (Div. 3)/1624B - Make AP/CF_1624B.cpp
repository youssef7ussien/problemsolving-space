/**
 * Title: "Make AP", Codeforces problem. 
 * Date: Friday, 29 April 2022 
 *
 */
/**
 * a = a
 * b = a + d        ==> d = b - a
 * c = a + 2 * d    ==> c = a + 2 * (b - a)
 * 
 * - new a = c - 2 * b
 * - new b = a + (c - a) / 2 ==> (a + c) / 2
 * - new c = a + 2 * (b - a) ==> 2 * b - a
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
        int a, b, c;
        cin>>a>>b>>c;
        bool can = ((2 * b - c) % a == 0   && (2 * b - c) > 0)
                || (((a + c) / 2) % b == 0 && (a + c) % 2 == 0)
                || ((2 * b - a) % c == 0   && (2 * b - a) > 0);

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}