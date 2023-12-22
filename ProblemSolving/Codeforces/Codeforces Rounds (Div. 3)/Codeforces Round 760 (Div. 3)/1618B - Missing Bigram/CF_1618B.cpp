/**
 * Title: "Missing Bigram" problem. 
 * Date: Tuesday, 14 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF               1e9

typedef long long         Long;
typedef pair<int, int>    PII;
typedef vector<int>       VI;
typedef vector<string>    VS;

int main()
{   
    FAST_IO;
    
    TEST_CASES(T)
    {
        int N;
        cin>>N;

        VS words(N-2);

        for(auto &it : words)
            cin>>it;
        
        string result = words[0];
        for(int i=0 ; i<SIZE(words)-1 ; i++)
            if(words[i][1] == words[i+1][0])
                result += words[i+1][1];
                else
                 result += words[i+1];

        while(SIZE(result) != N)
            result +='a';

        cout<<result<<"\n";

    }

    return 0;
}