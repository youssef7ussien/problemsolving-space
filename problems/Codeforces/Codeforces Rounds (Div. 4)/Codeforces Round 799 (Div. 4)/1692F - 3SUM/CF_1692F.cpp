/**
 * Title: "3SUM", Codeforces problem. 
 * Date: Tuesday, 14 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef vector<int>             VI;


bool twoSum(VI &freq, int num)
{
    for(int i = 0 ; i < 10 ; i++)
        if(freq[i]) {
            freq[i]--;
            if(num - i >= 0 && num - i < 10 && freq[num - i])
                return true;
            freq[i]++;
        }
    
    return false;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI freq(10);
        
        for(int i = 0 ; i < N ; i++) {
            CIN(num);
            freq[num % 10]++;
        }
        
        bool can = false;
        for(int i = 0 ; i < 10 ; i++)
            if(freq[i]) {
                freq[i]--;
                if(twoSum(freq, 3 - i) || twoSum(freq, 13 - i) || twoSum(freq, 23 - i))
                    { can = true; break; }
                freq[i]++;
            }

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}