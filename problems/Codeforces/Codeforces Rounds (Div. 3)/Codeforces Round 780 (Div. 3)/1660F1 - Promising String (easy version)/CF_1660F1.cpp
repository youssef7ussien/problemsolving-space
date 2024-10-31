/**
 * Title: "Promising String (easy version)", Codeforces problem. 
 * Date: Wednesday, 27 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;


int main()
{   
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        string str;
        cin>>N>>str;

        int counter = 0;
        for(int i = 0 ; i < N ; i++) {
            int count1 = 0, count2 = 0;
            for(int j = i ; j < N ; j++) {
                str[j] == '+' ? count1++ : count2++;
                counter += (count2 >= count1 && (count2 - count1) % 3 == 0);
            }
        }

        cout<<counter<<"\n";
    }
    
    return 0;
}