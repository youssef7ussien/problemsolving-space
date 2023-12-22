/**
 * Title: "Squares and Cubes", Codeforces problem. 
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
#define FILE_IN(file)     freopen(file, "r", stdin)
#define FILE_OUT(file)    freopen(file, "w", stdout)

typedef long long         Long;

int main()
{
    #ifdef DEBUG
        FILE_IN("__CF_1619b_input.txt");
        FILE_OUT("__CF_1619b_output.txt");
    #endif
    
    FAST_IO;
    
    TEST_CASES(T)
    {
        int N;
        cin>>N;

        cout<<((int)sqrt(N) + (int)cbrt(N) - (int)(sqrt(cbrt(N))))<<"\n";
    }

    return 0;
}