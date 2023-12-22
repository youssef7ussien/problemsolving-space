/**
 * Title: "Square String", Codeforces problem. 
 * Date: Monday, 20 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)     freopen(file, "r", stdin)
#define FILE_OUT(file)    freopen(file, "w", stdout)

bool solve(string str)
{  
    if(SIZE(str) % 2 != 0)
        return false;

    for(int i=0, j=SIZE(str)/2 ; i<SIZE(str)/2 && j<SIZE(str) ; i++, j++)
        if(str[i]!=str[j])
            return false;
    
    return true;
}

int main()
{
    #ifdef DEBUG
        FILE_IN("__CF_1619a_input.txt");
        FILE_OUT("__CF_1619a_output.txt");
    #endif
    
    FAST_IO;
    
    TEST_CASES(T)
    {
        string str;

        cin>>str;

        cout<<(solve(str) ? "YES" : "NO")<<"\n";
    }

    return 0;
}