/**
 * Title: "Bracket Sequence Deletion", Codeforces problem. 
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
        cin>>N;
        string str;
        cin>>str;

        int counter = 0, i = 0;
        while(i < N - 1) {
            if(str[i] == '(' && str[i + 1] == ')')
                i += 2;
            else {
                int j = i + 1;
                while(j < N && str[i] != str[j]) j++;
                if(j == N)
                    break;
                i = j + 1;
            }
            
            counter++;
        }

        cout<<counter<<" "<<N - i<<"\n";
    }
    
    return 0;
}