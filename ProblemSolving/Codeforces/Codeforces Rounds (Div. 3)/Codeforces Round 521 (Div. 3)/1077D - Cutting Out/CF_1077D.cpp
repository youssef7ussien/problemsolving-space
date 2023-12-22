/**
 * Title: "Cutting Out", Codeforces problem. 
 * Date: Monday, 04 April 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define CIN_TEMP(T)                 int T; cin>>T;
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef map<int, int>               MII;


bool check(const MII &freq, int K, int middle)
{
    int counter = 0;
    for(auto &it : freq)
        counter += it.second / middle;

    return counter >= K;
}

void print(const MII &freq, int K, int end)
{
    int counter = 0;
    for(auto &it : freq)
        for(int i = 0 ; i < it.second / end ; i++, counter++) {
            if(counter >= K) 
                { cout<<"\n"; return; }

            cout<<it.first<<" ";
        }

    cout<<"\n";
}

void solve(const MII &freq, int N, int K) 
{
    int left = 1, right = N;
    while(left <= right) {
        int middle = left + (right - left) / 2;

        if(check(freq, K, middle))
            left = middle + 1;
        else
            right = middle - 1;
    }

    print(freq, K, left - 1);
}

int main()
{
    FAST_IO;
    
    int N, K;
    cin>>N>>K;

    MII freq;
    for(int i = 0 ; i < N ; i++) {
        CIN_TEMP(temp)
        freq[temp]++;
    }
    
    solve(freq, N, K);
    return 0;
}