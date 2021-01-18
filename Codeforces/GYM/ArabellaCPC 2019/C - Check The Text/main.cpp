#include <bits/stdc++.h>
 
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    string arr="",arr1,arr2,arr3="";
    int t, n, q=0;
    cin>>t;
 
    for(int i=0 ; i<t ; i++)
    {
        if(i>0)
            arr+=" ";
        cin>>arr2;
        arr+=arr2;
    }
 
    cin>>n;
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr1;
        if(arr1=="Space")
            arr3+=" ";
        else if(arr1=="Backspace")
        {
            if(arr3.size()>0)
                arr3.pop_back();
        }
        else if(arr1=="CapsLock")
            q++;
        else
        {
            if(q%2!=0)
               arr1[0]=char(arr1[0]-32);
            arr3+=arr1;
        }
    }
    if(arr3==arr)
        cout<<"Correct"<<endl;
    else
        cout<<"Incorrect"<<endl;
 
    return 0;
}