/**
 * Title: "Plug-in", Codeforces problem. 
 * Date: Tuesday, 01 February 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)               freopen(file, "r", stdin)
#define FILE_OUT(file)              freopen(file, "w", stdout)


int main()
{   
    FAST_IO;
    string str, memory;
    cin>>str;

    for(auto &it : str)
        it == memory[SIZE(memory) ? SIZE(memory)-1 : 0] ? memory.pop_back() : memory.push_back(it);

    cout<<memory<<"\n";
    return 0;
}