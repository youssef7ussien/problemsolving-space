/**
 * Title: "Boats Competition", Codeforces problem. 
 * Date: Sunday, 20 March 2022 
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


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        VI numbers(N);
        for(auto &it : numbers)
            cin>>it;
        
        sort(ALL(numbers));
        
        int result = 0;
        for(int i = 2 ; i <= 2 * N ; i++) {
            int left = 0, right = N - 1, counter = 0;
            while(left < right) {
                if(numbers[left] + numbers[right] == i)
                    counter++, left++, right--;
                else if(numbers[left] + numbers[right] > i)
                    right--;
                else
                    left++;
            }

            result = max(result, counter);
        }

        cout<<result<<"\n";
    }
    
    return 0;
}