/**
 * Title: "The Fibonacci Segment", Codeforces problem. 
 * Date: Wednesday, 02 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;


int main()
{
    FAST_IO;
    
    int N;
    cin>>N;

    vector<int> numbers(N);
    for(auto &it : numbers)
        cin>>it;
    
    int result = min(2, N), counter = 2;
    for(int i = 2 ; i < N ; i++) {
        counter = (numbers[i-1] + numbers[i-2] == numbers[i] ? counter+1 : 2);
        result = max(result, counter);
    }

    cout<<result<<"\n";
    
    return 0;
}