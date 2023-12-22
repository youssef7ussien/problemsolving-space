/**
 * Title: "Queue", Codeforces problem. 
 * Date: Tuesday, 10 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    VI numbers(N);
    for(auto &it : numbers)
        cin>>it;
    
    sort(ALL(numbers));

    int counter = 0;
    Long prefix = 0;
    for(int i = 0 ; i < LEN(numbers) ; i++)
        if(numbers[i] >= prefix)
            counter++, prefix += numbers[i];
    
    cout<<counter<<"\n";
    return 0;
}