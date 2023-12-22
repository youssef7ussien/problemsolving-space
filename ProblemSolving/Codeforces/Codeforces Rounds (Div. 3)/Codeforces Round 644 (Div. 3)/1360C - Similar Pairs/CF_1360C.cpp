/**
 * Title: "Similar Pairs", Codeforces problem. 
 * Date: Tuesday, 10 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        

        int odd = 0, even = 0, count1 = 0;
        VI freq(101);
        
        for(int i = 0 ; i < N ; i++) {
            CIN(num);

            if(freq[num - 1]) {
                freq[num - 1]--, count1++;
            }
            else if(freq[num + 1]) {
                freq[num + 1]--, count1++;
            }
            else 
                freq[num]++;
            
            num % 2 ? odd++ : even++;
        }

        if(odd % 2 == 0 && even % 2 == 0)
                cout<<"YES\n";
        else if(count1 != 0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    
    return 0;
}