#include <iostream>
using namespace std;

int minNumber(string str)
{
    if(str.size()==2)
        return 0;

    int counter=0;
    for(int i=1 ; i<(int)str.size() ; i++)
        if(str[i]==str[i-1])
            counter++;

    return (counter+1)/2;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str>>str;
        cout<<minNumber(str)<<endl;
    }
    return 0;
}
