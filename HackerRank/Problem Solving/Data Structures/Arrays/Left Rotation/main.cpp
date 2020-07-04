#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int s,d;
    cin>>s>>d;
    vector<int> arr(s);
    for(int i=0;i<s;i++)
        cin>>arr[(s-d+i)%s];
    for(int i=0;i<s;i++)
        cout<<arr[i]<<" ";
    return 0;
}
