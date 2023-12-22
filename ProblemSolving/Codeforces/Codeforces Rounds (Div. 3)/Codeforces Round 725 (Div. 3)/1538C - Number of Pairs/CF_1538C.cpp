/**
 * Title: "Number of Pairs", Codeforces problem. 
 * Date: Thursday, 10 March 2022 
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


Long solve(VI numbers,int L,int R)
{
    sort(ALL(numbers));

    /**
     * Count numbers of element that n <= R - numbers[i]      ===> A | this numbers get with upper_bound
     * then count numbers of element that n >= L - numbers[i] ===> B | this numbers get with lower_bound
     * 
     * then the A - B is the number of element that L <= i + j <= R
     */
    Long counter = 0;
    for(int i = 0 ; i < SIZE(numbers) ; i++)
        counter += upper_bound(numbers.begin() + i + 1, numbers.end(), R - numbers[i]) - numbers.begin(),
        counter -= lower_bound(numbers.begin() + i + 1, numbers.end(), L - numbers[i]) - numbers.begin();

    return counter;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, L, R;
        cin>>N>>L>>R;

        VI numbers(N);
        for(auto &it : numbers)
            cin>>it;
        
        cout<<solve(numbers, L, R)<<"\n";
    }
    
    return 0;
}