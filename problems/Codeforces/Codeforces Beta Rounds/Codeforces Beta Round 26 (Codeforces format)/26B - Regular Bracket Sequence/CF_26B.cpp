/**
 * Title: "Regular Bracket Sequence", Codeforces problem. 
 * Date: Friday, 17 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define SIZE(v)           ((int)((v).size()))
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    stack<char> brackets;
    string str;
    cin>>str;

    int counter=0;
    for(const auto &it : str)
        if(it=='(')
            brackets.push(it);
        else if(it==')' && !brackets.empty())
            brackets.pop(), counter+=2;

    cout<<counter<<"\n";

    return 0;
}