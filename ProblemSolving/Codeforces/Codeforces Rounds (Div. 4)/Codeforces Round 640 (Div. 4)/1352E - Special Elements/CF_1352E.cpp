/**
 * Title: "Special Elements", Codeforces problem. 
 * Date: Thursday, 21 April 2022 
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

        VI numbers(N), freq(N + 1);
        for(auto &it : numbers) {   
            cin>>it;
            freq[it]++;
        }

        int counter = 0;
        for(int i = 0 ; i < N ; i++) {
            int current = numbers[i];
            for(int j = i + 1 ; j < N ; j++) {
                current += numbers[j];
                if(current <= N)
                    counter += freq[current], freq[current] = 0;
            }
        }

        cout<<counter<<"\n";
    }
    
    return 0;
}