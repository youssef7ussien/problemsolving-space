/**
 * Title: "Add All", UVA Online Judge problem. 
 * Date: Sunday, 19 December 2021 
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

int main()
{
    #ifdef DEBUG
        FILE_IN("__UVA_10954_input.txt");
        FILE_OUT("__UVA_10954_output.txt");
    #endif
    
    FAST_IO;
    
    int N;
    while((cin>>N) && N!=0)
    {
        
        priority_queue<int, vector<int>, greater<int>> numbers;

        for(int i=0 ; i<N ; i++)
        {
            int num; cin>>num;
            numbers.push(num);
        }

        Long result = 0, total = 0;
        while(SIZE(numbers) > 1)
        {
            total = numbers.top(), numbers.pop();
            total += numbers.top(), numbers.pop();
            result += total;
            numbers.push(total);
        }

        cout<<result<<"\n";
    }
    
    return 0;
}