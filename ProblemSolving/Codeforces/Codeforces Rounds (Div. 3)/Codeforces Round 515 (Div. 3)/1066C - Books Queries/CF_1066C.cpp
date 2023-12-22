/**
 * Title: "Books Queries", Codeforces problem. 
 * Date: Monday, 27 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    VI places(int(2e5 + 2));

    int Q, left = -1, right = 1;
    cin>>Q;

    for(int i = 0 ; i < Q ; i++) {
        char type; int id;
        cin>>type>>id;
        
        if(i == 0)
            places[id] = 0;
        else if(type == 'L')
            places[id] = left--;
        else if(type == 'R')
            places[id] = right++;
        else
            cout<<min(right - places[id] - 1, abs(left - places[id]) - 1)<<"\n";
    }
    
    return 0;
}