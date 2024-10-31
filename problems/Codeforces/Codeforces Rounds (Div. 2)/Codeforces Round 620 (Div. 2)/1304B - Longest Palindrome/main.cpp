#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())

void print(const vector<string> &leftStr,string middleStr,const vector<string> &rightStr)
{
    cout<<((SIZE(leftStr)!=0 ? SIZE(leftStr)*SIZE(leftStr[0])*2 : 0) + SIZE(middleStr))<<"\n";

    for(auto &it : leftStr)
        cout<<it;

    cout<<middleStr;

    for(auto it=rightStr.rbegin() ; it<rightStr.rend() ; it++)
        cout<<*it;

    cout<<"\n";
}

int main()
{
    int N, M;
    cin>>N>>M;

    set<string> stringsSet;
    vector<string> strings(N), leftStr, rightStr;
    string middleStr="";

    for(auto &it : strings)
    {
        cin>>it;
        stringsSet.insert(it);
    }

    for(auto &it : strings)
    {
        string temp=string(it.rbegin(), it.rend());

        if(temp==it)
            middleStr=it;

        else if(stringsSet.find(temp) != stringsSet.end())
            leftStr.push_back(it), rightStr.push_back(temp),
            stringsSet.erase(it), stringsSet.erase(temp);
    }

    print(leftStr, middleStr, rightStr);

    return 0;
}
