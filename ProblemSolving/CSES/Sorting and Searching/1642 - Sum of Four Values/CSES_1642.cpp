#include <bits/stdc++.h>

using namespace std;

#define ALL(v)               ((v).begin()), ((v).end())
#define R_ALL(v)             ((v).rbegin()), ((v).rend())
#define FAST_IO              ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                   first
#define SS                   second

int main()
{
    FAST_IO;
    
    int N, sum;
    cin>>N>>sum;

    vector<int> numbers(N);
    for(auto &it : numbers)
        cin>>it;

    map<int, pair<int, int>> freq;
    for(int i = 0 ; i < N ; i++) {
        for(int j = i + 1 ; j < N ; j++)
            if(freq[sum - numbers[i] - numbers[j]] != make_pair(0, 0)) {
                cout<<freq[sum - numbers[i] - numbers[j]].FF<<" "
                    <<freq[sum - numbers[i] - numbers[j]].SS<<" "
                    <<i + 1<<" "<<j + 1<<"\n";
                return 0;
            }

        for(int j = 0 ; j < i ; j++)
            freq[numbers[i] + numbers[j]] = {j + 1, i + 1};
    }

    cout<<"IMPOSSIBLE"<<"\n";
    return 0;
}