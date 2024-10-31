/**
 * Title: "Substrings Sort", Codeforces problem. 
 * Date: Thursday, 03 February 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define LOOP(start, stop, steps)    for(int _i=start ; (steps>0 ? _i<stop : _i>stop) ; _i+=steps)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)               freopen(file, "r", stdin)
#define FILE_OUT(file)              freopen(file, "w", stdout)


bool findSub(const vector<string> &strings) 
{
    for (int i = 1 ; i < SIZE(strings) ; i++)
        if(strings[i].find(strings[i - 1]) == string::npos) 
            return false;
    return true;
}

int main()
{
    #ifdef __DEBUG
        FILE_IN("samples\\__CF_988B.in");
        FILE_OUT("samples\\__CF_988B.out");
    #endif
    
    FAST_IO;
    
    int N;
    cin>>N;

    vector<string> strings(N);

    for(auto &it : strings) 
        cin>>it;
    
    sort(ALL(strings), [](const string &a, const string &b) {
        return a.size() == b.size() ? a < b : a.size() < b.size();
    });

    if(findSub(strings)) {
        cout<<"YES"<<"\n";
        for(auto &it : strings) 
            cout<<it<<"\n";
    }
    else
        cout<<"NO"<<"\n";

    return 0;
}