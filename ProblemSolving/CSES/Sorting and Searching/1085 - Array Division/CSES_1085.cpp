/**
 * Title: "Array Division", CSES problem. 
 * Date: Monday, 07 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9+5

typedef long long                   Long;
typedef pair<int, Long>             PIL;
typedef vector<int>                 VI;


bool check(const VI &numbers, int K, Long middle)
{
    Long sum = 0;
    int counter = 1;
    for(int i = 0 ; i < SIZE(numbers) ; i++) {
        if(sum + numbers[i] > middle)
            sum = 0, counter++;

        sum += numbers[i];
    }
    
    return counter <= K;
}

Long binarySearch(const VI &numbers, int K, PIL range)
{
    Long left = range.first, right = range.second;
    while(left < right) {
        Long middle = left + (right - left) / 2;
        
        check(numbers, K, middle) ? right = middle : left = middle + 1;
    }

    return right;
}

int main()
{
    FAST_IO;
    
    int N, K;
    cin>>N>>K;

    VI numbers(N);
    PIL range = {-INF, 0};
    for(auto &it : numbers) {
        cin>>it;
        range = {max(range.first, it), range.second + it};
    }
    
    cout<<binarySearch(numbers, K, range)<<"\n";
    return 0;
}

