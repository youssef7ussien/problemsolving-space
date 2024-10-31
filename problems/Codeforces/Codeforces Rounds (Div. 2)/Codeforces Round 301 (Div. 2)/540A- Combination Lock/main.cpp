#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    int num,sum=0,a;
    string s1,s2;
    cin>>num>>s1>>s2;
    for(int i=0;i<num;i++)
    {
        a=abs(s1[i]-s2[i]);
        if(a>5)
            a=10-a;
        sum+=a;
    }
    cout<<sum<<endl;
    return 0;
}
