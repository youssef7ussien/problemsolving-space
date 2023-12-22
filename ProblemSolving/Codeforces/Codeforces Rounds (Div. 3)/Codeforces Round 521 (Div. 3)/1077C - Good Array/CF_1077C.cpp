/**
 * Title: "Good Array", Codeforces problem. 
 * Date: Saturday, 02 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define SIZE(v)                 ((int)((v).size()))
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    int N;
    cin>>N;

    VI numbers(N), result;
    map<Long, int> freq;
    Long prefix = 0;

    for(auto &it : numbers) {
        cin>>it;
        freq[it]++, prefix += it;
    }

    for(int i = 0 ; i < N ; i++) {
        prefix -= numbers[i], freq[numbers[i]]--;

        if(prefix % 2 == 0 && freq[prefix / 2] > 0)
            result.push_back(i + 1);

        prefix += numbers[i], freq[numbers[i]]++;
    }

    cout<<SIZE(result)<<"\n";
    for(auto &it : result)
        cout<<it<<" ";
    cout<<"\n";
    
    return 0;
}