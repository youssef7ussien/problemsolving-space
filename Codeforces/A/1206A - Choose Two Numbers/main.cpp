#include <iostream>
#include <vector>

using namespace std;

int cinVector()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    int maxNum=0;
    for(int i=0 ; i<n ; i++)
    {
        cin>>vec[i];
        if(maxNum<vec[i])
            maxNum=vec[i];
    }

    return maxNum;
}

int main()
{
    int num[2]={cinVector(),cinVector()};
    cout<<num[0]<<" "<<num[1];

    return 0;
}
