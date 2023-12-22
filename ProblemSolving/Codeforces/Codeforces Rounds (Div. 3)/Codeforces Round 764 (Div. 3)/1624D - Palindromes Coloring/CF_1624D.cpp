/**
 * Title: "Palindromes Coloring", Codeforces problem. 
 * Date: Friday, 29 April 2022 
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
        int N, K;
        string str;
        cin>>N>>K>>str;

        VI freq(26);
        for(auto &it : str)
            freq[it - 'a']++;
        
        int countPairs = 0, countOdd = 0;
        for(auto &it : freq)
            countPairs += it / 2, countOdd += it % 2;
        
        cout<<(2 * (countPairs / K) + (2 * (countPairs % K) + countOdd >= K))<<"\n";
    }
    
    return 0;
}