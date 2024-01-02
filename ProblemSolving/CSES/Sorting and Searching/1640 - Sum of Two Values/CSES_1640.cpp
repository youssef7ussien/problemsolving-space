/**
 * Title: "Sum of Two Values", CSES problem. 
 * Date: Friday, 11 March 2022 
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


int main()
{
    FAST_IO;
    
    int N, sum;
    cin>>N>>sum;

    vector<pair<int, int>> numbers(N);
    for(int i = 0 ; i < N ; i++) {
        cin>>numbers[i].first;
        numbers[i].second = i + 1;
    }

    sort(ALL(numbers));
    
    bool found = false;
    int left = 0, right = N - 1;
    while(left < right) {
        if(numbers[left].first + numbers[right].first > sum)
            right--;
        else if(numbers[left].first + numbers[right].first < sum)
            left++;
        else
            { found = true; break; }        
    }

    if(found) 
        cout<<min(numbers[right].second, numbers[left].second)
            <<" "<<max(numbers[right].second, numbers[left].second)<<"\n";
    else
        cout<<"IMPOSSIBLE"<<"\n";
    return 0;
}