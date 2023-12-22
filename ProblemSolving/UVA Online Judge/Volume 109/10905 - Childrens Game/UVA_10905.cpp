/**
 * Title: "Childrens Game", UVA Online Judge problem. 
 * Date: Friday, 17 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)     freopen(file, "r", stdin)
#define FILE_OUT(file)    freopen(file, "w", stdout)

typedef long long         Long;
typedef pair<int, int>    PII;
typedef vector<int>       VI;
typedef vector<string>    VS;

int main()
{
    #ifdef DEBUG
        FILE_IN("__UVA_10905_input.txt");
        FILE_OUT("__UVA_10905_output.txt");
    #endif
    
    FAST_IO;
    
    int N;

    while((cin>>N) && N!=0)
    {
        vector<string> numbers(N);
        for(auto &it : numbers)
            cin>>it;
        
        sort(ALL(numbers), [](string a, string b) { return (a+b > b+a); });

        for(const auto &it : numbers)
            cout<<it;
        cout<<"\n";
    }
    
    return 0;
}