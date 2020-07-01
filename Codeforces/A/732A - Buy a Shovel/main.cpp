#include <iostream>
using namespace std;
int main()
{
    int k,r;
    cin>>k>>r;
    int sum=k,counter=1;
    while(sum%10!=r && sum%10!=0)
    { sum+=k; counter++; }
    cout<<counter<<endl;
    return 0;
}
