#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> arr)
{
    sort(arr.begin(),arr.end());

    int difference=abs(arr[0]-arr[1]);
    for(int i=1 ; i<(int)arr.size()-1 ; i++)
        difference=min(abs(arr[i]-arr[i+1]),difference);

    return difference;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0 ; i<n ; i++)
        cin>>arr[i];

    cout<<solve(arr)<<endl;
    return 0;
}
