#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define LEN(v)                  ((int)((v).size()))
#define CHAR(c)                 (c-'a')
typedef long long               Long;


Long numSubString(const string &str1, const string &str2, int k)
{
    vector<vector<bool>> substringsA(26, vector<bool>(26));

    for(int i = 0 ; i <= LEN(str1) - k ; i++)
        substringsA[CHAR(str1[i + k - 1])][CHAR(str1[i])] = true;

    Long counter = 0;
    vector<Long> freq(26);

    for(int i = 0 ; i < LEN(str2) ; i++) {
        freq[CHAR(str2[i])]++;
        for(int j = 0 ; j < 26 ; j++)
            if(substringsA[CHAR(str2[i])][j])
                counter += freq[j];
    }

    return counter;
}

int main()
{
    FAST_IO;

    TEST_CASES(T) {
        int k;  // N & M not used in this code
        string str1, str2;
        cin>>str1>>str1>>k>>str1>>str2;

        cout<<numSubString(str1, str2, k)<<"\n";
    }

    return 0;
}
