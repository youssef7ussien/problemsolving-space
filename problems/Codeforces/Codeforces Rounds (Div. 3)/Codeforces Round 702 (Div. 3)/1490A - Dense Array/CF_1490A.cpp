/**
 * Title: "Dense Array", Codeforces problem. 
 * Date: Saturday, 02 July 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        int counter = 0;
        for(int i = 0, last = 0 ; i < N ; i++) {
            CIN(num);
            
            int minN = min(last, num), maxN = max(last, num);
            while(i != 0 &&  minN * 2 < maxN)
                counter++, minN *= 2;

            last = num;
        }
        
        cout<<counter<<"\n";
    }
    
    return 0;
}