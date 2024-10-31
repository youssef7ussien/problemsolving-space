/**
 * Title: "Colourblindness", Codeforces problem. 
 * Date: Tuesday, 30 August 2022 
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
        int N;
        string str1, str2;
        cin>>N>>str1>>str2;

        bool can = true;
        for(int i = 0 ; i < N ; i++)
            if((str1[i] == 'R' && str2[i] != 'R') || (str1[i] != 'R' && str2[i] == 'R'))
                { can = false; break; }
        
        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}