#include <iostream>

using namespace std;

int main()
{
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++)
        cout<<str[i];
    for(int i=str.size()-1;i>=0;i--)
        cout<<str[i];

    return 0;
}
