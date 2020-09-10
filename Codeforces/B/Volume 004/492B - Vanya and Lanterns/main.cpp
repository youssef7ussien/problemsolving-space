#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    int numLanterns,lenght;
    double maxLength=0;
    cin>>numLanterns>>lenght;

    vector<double>location(numLanterns);
    for(int i=0;i<numLanterns;i++)
        cin>>location[i];
    sort(location.begin(),location.end());

    if(location[0]>(lenght-location[numLanterns-1]))
        maxLength=location[0];
    else
        maxLength=lenght-location[numLanterns-1];

    for(int i=0;i<numLanterns-1;i++)
        if((location[i+1]-location[i])/2>maxLength)
            maxLength=(location[i+1]-location[i])/2;

    cout<<fixed<<setprecision(10)<<maxLength<<endl;
    return 0;
}
