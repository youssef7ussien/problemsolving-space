#include <iostream>
using namespace std;
int main()
{
    int s; cin>>s;
    int *arr=new int[s] , counter=0;
    for(int i=0;i<s;i++)
        cin>>arr[i];
    bool swaped=false;
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
            if(arr[j]!=j+1)
            {
                int cpy=arr[j];
                arr[j]=arr[cpy-1];
                arr[cpy-1]=cpy;
                counter++; swaped=true;
            }
        if(swaped) swaped=false;
        else
        {
            cout<<counter<<endl;
            delete[] arr;
            return 0;
        }
    }
    return 0;
}
