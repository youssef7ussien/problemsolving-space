/**
 * Title: "Binary String", Codeforces problem. 
 * Date: Friday, 13 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef vector<int>             VI;

int check(const string &str, int middle)
{
    int left = 0, right = 0, maxOnes = 0, count0 = 0, count1 = 0;
    while(right < LEN(str)) {
        str[right++] == '0' ? count0++ : count1++;
        maxOnes = max(maxOnes, count1);
        if(count0 > middle)
            str[left++] == '0' ? count0-- : count1--;
    }

    return maxOnes;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        string str;
        cin>>str;
        
        int countOnes = count(ALL(str), '1');
        int left = 0, right = LEN(str) - countOnes;

        while(left < right) {
            int middle = left + (right - left) / 2;

            countOnes - check(str, middle) <= middle ? right = middle : left = middle + 1;
        }

        cout<<right<<"\n";
    }
    
    return 0;
}