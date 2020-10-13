#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long Long;

Long maximumProduct(vector<Long> arr)
{
    Long maxProduct=1;

    sort(arr.begin(),arr.end());

    if(arr[arr.size()-1]<=0)
    {
        for (int i=(int)arr.size()-1 ; i>=(int)arr.size()-5 ; i--)
            maxProduct*=arr[i];
        return maxProduct;
    }

    maxProduct*=arr[arr.size()-1];
    int left=0, right=(int)arr.size()-2;

    for(int i=0 ; i<2 ; i++) // i < (5/2 = 2.5 = 2)
    {
        Long leftProduct=arr[left]*arr[left+1];
        Long rightProduct=arr[right]*arr[right-1];

        if(leftProduct>rightProduct)
            { maxProduct*=leftProduct; left+=2; }
        else
            { maxProduct*=rightProduct; right-=2; }
    }

    return maxProduct;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<Long> arr(n);
        for(int i=0 ; i<n ;i++)
            cin>>arr[i];

        cout<<maximumProduct(arr)<<endl;
    }
    return 0;
}
