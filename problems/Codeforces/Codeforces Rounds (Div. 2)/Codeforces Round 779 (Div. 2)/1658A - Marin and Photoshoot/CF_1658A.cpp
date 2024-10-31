/**
 * Title: "Marin and Photoshoot", Codeforces problem. 
 * Date: Sunday, 27 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        string str;
        cin>>N>>str;

        int counter = 0;
        for(int i = 0 ; i < N - 1 ; i++) {
            if(str[i] == '0' && str[i + 1] == '0')
                counter += 2;
            else if(i < N - 2 && str[i] == '0' && str[i + 1] == '1' && str[i + 2] == '0')
                counter += 1;
        }

        cout<<counter<<"\n";
    }
    
    return 0;
}