#include <iostream>

using namespace std;
#define SIZE(s) ((int)s.size())

string divideStr(string str)
{
    if(SIZE(str)&1)
        return str;
    string subStr1=divideStr(str.substr(0,SIZE(str)/2)), subStr2=divideStr(str.substr(SIZE(str)/2));

    return subStr1 < subStr2 ? subStr1+subStr2 : subStr2+subStr1;

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    string str1, str2;
    cin>>str1>>str2;

    divideStr(str1)==divideStr(str2) ? cout<<"YES\n" : cout<<"NO\n";

    return 0;
}
