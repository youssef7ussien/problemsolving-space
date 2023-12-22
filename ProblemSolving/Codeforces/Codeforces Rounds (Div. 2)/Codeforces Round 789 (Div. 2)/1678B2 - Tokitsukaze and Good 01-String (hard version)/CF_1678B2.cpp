/**
 * Title: "Tokitsukaze and Good 01-String (hard version)", Codeforces problem. 
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

        int counter = 0, countSeg = 0; 
        char last = 0;

        for(int i = 0 ; i < N - 1 ; i += 2) {
            if(str[i] != str[i + 1])
                counter++;
            else
                countSeg += (last != str[i]), last = str[i];
        }

        cout<<counter<<" "<<countSeg + (countSeg == 0)<<"\n";
    }

    return 0;
}