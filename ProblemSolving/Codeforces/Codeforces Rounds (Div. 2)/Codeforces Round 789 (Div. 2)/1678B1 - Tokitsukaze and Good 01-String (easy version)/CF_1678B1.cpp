/**
 * Title: "Tokitsukaze and Good 01-String (easy version)", Codeforces problem. 
 * Date: Sunday, 08 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N; 
        string str;
        cin>>N>>str;

        int counter = 0, last = 0;
        for(int i = 0 ; i < N ; i++) {
            if(str[i] == str[i + 1])
                last++;
            else if ((last + 1) % 2 != 0) {
                counter += 1;
                last = 1;
            }
            else
                last = 0;
        }
        cout<<counter<<"\n";
    }
    
    return 0;
}