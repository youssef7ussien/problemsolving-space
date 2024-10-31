#include <iostream>
#include <string>
using namespace std;
int main()
{
    int arr[4],sum=0;     string second;
    for(int i=0;i<4;i++)
        cin>>arr[i];
    cin>>second;
    for(int i=0;i<second.size();i++)
        sum+=arr[second[i]-'1'];
    cout<<sum<<endl;
    return 0;
}
