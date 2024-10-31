/**
 * Title: "Equalize the Remainders", Codeforces problem. 
 * Date: Wednesday, 02 February 2022 
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

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;


int main()
{   
    #ifdef __DEBUG
        FILE_IN("samples\\__CF_999D.in");
        FILE_OUT("samples\\__CF_999D.out");
    #endif

    FAST_IO;
    int N, M;
    cin>>N>>M;

    VI numbers(N);
    pair<VI, set<int>> groups;
    
    for(auto &it : numbers)
        cin>>it;

    groups.first.resize(M);
    LOOP(0, M, 1)
        groups.second.insert(_i);
    
    Long counter = 0;
    for(auto &it : numbers) {
        int remind = it % M;
        int group = remind > *groups.second.crbegin() ? *groups.second.cbegin() : *groups.second.lower_bound(remind);
        
        if(++groups.first[group] == N / M)
            groups.second.erase(group);
        
        it += (group - remind + M) % M;
        counter += (group - remind + M) % M;
    }
    
    cout<<counter<<"\n";
    for(auto &it : numbers)
        cout<<it<<" ";
    cout<<"\n";

    return 0;
}