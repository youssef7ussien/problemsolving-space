#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumToys(vector<int> prices, int amountSpend)
{
    int numToys=-1;

    sort(prices.begin(),prices.end());

    while(amountSpend>0)
        amountSpend-=prices[++numToys];

    return numToys;
}

int main()
{
    int numPrices,amountSpend;
    cin>>numPrices>>amountSpend;

    vector<int> prices(numPrices);
    for(int i=0 ; i<numPrices ; i++)
        cin>>prices[i];

    cout<<maximumToys(prices,amountSpend)<<endl;

    return 0;
}
