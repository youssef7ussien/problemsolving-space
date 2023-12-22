#include <iostream>
#include <set>

using namespace std;

int main()
{
    int numTV,numCarry,sumPrice=0;
    cin>>numTV>>numCarry;
    multiset<int>priceTVs;

    auto it=priceTVs.begin();
    for(int i=0;i<numTV;i++)
    {
        int price;  cin>>price;
        it=priceTVs.emplace_hint(it,price);
    }

    it=priceTVs.begin();
    for(int i=0;i<numCarry;i++)
    {
        if(*it>0) break;
        sumPrice+=*it++;
    }
    cout<<abs(sumPrice)<<endl;

    return 0;
}
