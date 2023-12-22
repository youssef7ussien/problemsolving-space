/**
 * Title: "Balanced Team", Codeforces problem. 
 * Date: Saturday, 05 March 2022 
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
    
    const int diff = 5;
    int N;
    cin>>N;
    
    VI students(N);
    for(auto &it : students)
        cin>>it;

    sort(ALL(students));

    int left = SIZE(students)-2, right = SIZE(students)-1, counter = 1;
    while(left >= 0) {
        if(students[right] - students[left--] > diff)
            right--;
        else
            counter++;
    }

    cout<<counter<<"\n";
    return 0;
}