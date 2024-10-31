/**
 * Title: "Heaters", Codeforces problem. 
 * Date: Sunday, 26 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    int N, R;
    cin>>N>>R;
    
    set<int> pos;
    for(int i = 0 ; i < N ; i++) {
        CIN(num);
        if(num == 1) 
            pos.insert(i);
    }

    if(pos.empty())
        { cout<<"-1\n"; return 0; }

    int current = 0, counter = 0;
    while(current < N) {
        auto it = pos.upper_bound(current + R - 1);
        
        if(it == pos.begin())
            { counter = -1; break; }

        if(current >= *prev(it) - R + 1 && current <= *prev(it) + R - 1)
            current = *prev(it) + R, counter++;
        else
            { counter = -1; break; }

    }

    cout<<counter<<"\n";
    return 0;
}

