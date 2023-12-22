#include <iostream>
using namespace std;
int main()
{
    int n,k;
    char arr[26];
    for(int i=0;i<26;i++)
        arr[i]=i+'a';
    cin>>n>>k;
    for(int i=0,j=0;i<n;i++,j++)
    {
        if(j>k-1) j=0;
        cout<<arr[j];
    }
    return 0;
}
