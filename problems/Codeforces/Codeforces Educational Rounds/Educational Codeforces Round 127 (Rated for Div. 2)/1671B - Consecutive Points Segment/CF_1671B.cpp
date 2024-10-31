/**
 * Title: "Consecutive Points Segment", Codeforces problem. 
 * Date: Friday, 22 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<PII>             VII;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        VI points(N);
        for(auto &it : points)
            cin>>it;
        
        bool can = true;
        int count2 = 0, count3 = 0;
        for(int i =0 ; i < N - 1 ; i++) {
            count3 += (points[i + 1] - points[i] == 3);
            count2 += (points[i + 1] - points[i] == 2);

            if(points[i + 1] - points[i] > 3 || (count3 != 0 && count2 != 0) || count3 >= 2 || count2 >= 3) 
                { can = false; break; }
        }

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}