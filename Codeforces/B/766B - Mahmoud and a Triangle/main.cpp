#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>lines(num);
    for(int i=0;i<num;i++)
        cin>>lines[i];
    sort(lines.begin(),lines.end());
    for(int i=0;i<num-2;i++)
        if(lines[i]+lines[i+1]>lines[i+2])
        { cout<<"YES"<<endl; return 0; }

    cout<<"NO"<<endl;
    return 0;
}
