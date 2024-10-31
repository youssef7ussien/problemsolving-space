/**
 * Title: "Make a Power of Two", Codeforces problem. 
 * Date: Sunday, 01 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     int(1e9 + 1)
#define MAX                     Long(1e18)
typedef long long               Long;


int countDiff(string str, string power)
{
    int count = 0;
    for(int i = 0, j = 0 ; i < SIZE(str) && j < SIZE(power); i++) {
        if(str[i] == power[j])
            j++, count++;
    }

    return SIZE(str) - count + SIZE(power) - count;
}

int main()
{
    FAST_IO;
    
    vector<string> powerTwo;
    for(Long i = 1 ; i <= MAX ; i *= 2)
        powerTwo.push_back(to_string(i));

    TEST_CASES(T) {
        string str;
        cin>>str;

        int result = INF;
        for(auto &it : powerTwo)
            result = min(result, countDiff(str, it));

        cout<<result<<"\n";
    }

    return 0;
}