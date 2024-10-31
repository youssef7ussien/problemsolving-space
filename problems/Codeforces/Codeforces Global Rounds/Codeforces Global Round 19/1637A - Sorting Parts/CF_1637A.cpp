/**
 * Title: "Sorting Parts", Codeforces problem. 
 * Date: Saturday, 12 February 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define LOOP(start, stop, steps)    for(int _i=start ; (steps>0 ? _i<stop : _i>stop) ; _i+=steps)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)               freopen(file, "r", stdin)
#define FILE_OUT(file)              freopen(file, "w", stdout)
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;
typedef vector<PII>                 VII;


int main()
{
    #ifdef __DEBUG
        FILE_IN("samples\\__CF_1637A.in");
        FILE_OUT("samples\\__CF_1637A.out");
    #endif
    
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        VI numbers(N);

        bool sorted = true;
        for(int i = 0 ; i < N ; i++) {
            cin>>numbers[i];
            if(i != 0 && numbers[i - 1] > numbers[i])
                sorted = false;
        }

        cout<<(sorted ? "NO" : "YES")<<"\n";
    }
    
    return 0;
}