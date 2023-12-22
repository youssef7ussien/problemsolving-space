/**
 * Title: "Fighting Tournament", Codeforces problem. 
 * Date: Tuesday, 16 August 2022 
 *
 */

/**
 * observation: if largest number is the first then it is win forever.
 * 
 * calculate first n rounds and store (round, numbers of wins) for each player.
 * there three case in this problem:
 * case 1: if k > n && i == n then result = (numbers of wins for arr[i]) + (k - n).
 * case 2: if k > n then result = numbers of wins for arr[i].
 * case 3: if k <= n then result = numbers of wins for arr[i] to the nearest round less than or equal to k.
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second

typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<PII>             VII;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, Q;
        cin>>N>>Q;

        VI arr(N);
        for(auto &it : arr)
            cin>>it;
        
        vector<VII> wins(N + 2);
        for(auto &it : wins) it.push_back({0, 0});

        for(int i = 1, j = 0 ; i <= N ; i++) {
            if(arr[i % N] > arr[j])
                j = i;

            wins[j + 1].push_back({i, wins[j + 1].back().SS + 1});
        }

        while(Q--) {
            int i, k;
            cin>>i>>k;

            if(k > N)
                cout<<wins[i].back().SS + (arr[i - 1] == N ? k - N : 0)<<"\n";
            else {
                auto it = upper_bound(ALL(wins[i]), k, [](int b, const PII &a){ return a.first > b; }) - 1;               
                cout<<it->SS<<"\n";
            }
        }
    }
    
    return 0;
}
