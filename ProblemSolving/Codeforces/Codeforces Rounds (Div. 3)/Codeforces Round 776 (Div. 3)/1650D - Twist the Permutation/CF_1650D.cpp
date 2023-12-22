/**
 * Title: "Twist the Permutation", Codeforces problem. 
 * Date: Wednesday, 09 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;
typedef vector<PII>                 VII;

void solve(deque<int> numbers)
{
    int N = SIZE(numbers);
    VI result(N);

    for(int i = N - 1 ; i > 0 ; i--) {
        int index = 0;
        for(int j = 0 ; j <= i ; j++)
            if(numbers[j] == i + 1)
                index = j + 1;
        
        for(int k = 0 ; k < index ; k++)
                numbers.push_back(numbers.front()), numbers.pop_front();
        numbers.pop_back();

        result[i] = index % (i + 1);
    }

    for(auto &it : result)
        cout<<it<<" ";
    cout<<"\n";
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        deque<int> numbers(N);
        for(auto &it : numbers)
            cin>>it;
        
        solve(numbers);
    }
    
    return 0;
}