/**
 * Title: "Yet Another Problem About Pairs Satisfying an Inequality", Codeforces problem. 
 * Date: Thursday, 21 July 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<PII>             VII;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VII arr;
        for(int i = 1 ; i <= N ; i++) {
            int num;
            cin>>num;

            if(num < i)
                arr.push_back({num, i});
        }
        
        sort(ALL(arr));

        Long counter = 0;
        for(auto &it : arr)
            counter += arr.end() - upper_bound(ALL(arr), it.second, [](int a, const PII &b) {
                return a < b.first;
            });

        cout<<counter<<"\n";
    }
    
    return 0;
}