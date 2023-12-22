/**
 * Title: "Autocomplete", Codeforces problem. 
 * Date: Sunday, 19 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{   
    FAST_IO;

    int N;
    string str;
    cin>>str>>N;

    set<string> strings;

    for(int i=0 ; i<N ; i++) {
        string temp; cin>>temp;
        strings.insert(temp);
    }

    set<string>::iterator it = find_if(ALL(strings), [str](string a) { return a.find(str) == 0; });
    cout<<(it != strings.end() ? *it : str)<<"\n";
    
    return 0;
}