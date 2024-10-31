#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str; long long n ;
    cin>>str>>n;
    long long length=str.size() , repeat=n/length , x=n%length , cnt=0 , xCnt=0 ;
    for(int i=0;i<length;i++)
    {
        if(str[i]=='a') cnt++;
        if(str[i]=='a' && i<x) xCnt++;
    }
    cout<<(cnt*repeat)+xCnt<<endl;
    return 0;
}
