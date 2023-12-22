/**
 * Title: "Balanced Remainders", Codeforces problem. 
 * Date: Saturday, 02 July 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI freq(3);
        for(int i = 0 ; i < N ; i++) {
            int num;
            cin>>num;
            freq[num % 3]++;
        }

        int counter = 0;
        while(min(freq[0], min(freq[1], freq[2])) != N / 3)
            if(freq[0] > N / 3)
                counter++, freq[0]--, freq[1]++;
            else if(freq[1] > N / 3)
                counter++, freq[1]--, freq[2]++;
            else if(freq[2] > N / 3)
                counter++, freq[2]--, freq[0]++;
        
        cout<<counter<<"\n";
    }
    
    return 0;
}