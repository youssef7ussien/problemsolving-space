#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define PI 3.141592654
#define Radius(S,V) (S/(2*sin(PI/V))) // C++ works in radians

int main()
{
    int V,S;
    cin>>V>>S;
    cout<<fixed<<setprecision(9)<<(double)(PI*Radius(S,V)*Radius(S,V))<<"\n";
    return 0;
}
