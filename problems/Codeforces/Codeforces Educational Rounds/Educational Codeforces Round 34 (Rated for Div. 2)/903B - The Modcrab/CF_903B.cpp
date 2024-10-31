/**
 * Title: "The Modcrab", Codeforces problem. 
 * Date: Tuesday, 28 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    int h1, a1, c1, h2, a2;
    cin>>h1>>a1>>c1>>h2>>a2;

    vector<char> result;
    while(h2 > 0) {
        if(h1 <= a2 && h2 > a1)
            result.push_back('H'), h1 += c1;
        else
            result.push_back('S'), h2 -= a1;

        h1 -= a2;
    }
    
    cout<<LEN(result)<<"\n";
    for(auto &it : result)
        cout<<(it == 'S' ? "STRIKE" : "HEAL")<<"\n";

    return 0;
}