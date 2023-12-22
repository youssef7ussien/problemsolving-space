#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int num; cin>>num;
    vector<int>section(num);
    vector<int>counter(num,1);
    for(int i=0;i<num;i++)
        cin>>section[i];
    for(int i=0;i<num;i++)
    {
        for(int j=i;j>0;j--) // left
            if(section[j]<section[j-1])
                break;
            else
                counter[i]++;
        for(int j=i;j<num-1;j++)  // right
            if(section[j]<section[j+1])
                break;
            else
                counter[i]++;
    }
    sort(counter.begin(),counter.end());
    cout<<counter[num-1]<<endl;
    return 0;
}
