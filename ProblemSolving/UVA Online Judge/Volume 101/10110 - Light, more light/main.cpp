#include <iostream>
#include <cmath>

using namespace std;

#define lastLight(sqrtNum) (sqrtNum-(int)sqrtNum==0 ? "yes" : "no")

int main()
{
    long long num=1;
    while(cin>>num && num!=0)
        cout<<lastLight(sqrt(num))<<endl;

    return 0;
}
