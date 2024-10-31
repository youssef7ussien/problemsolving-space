#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Point {
    int X=0,Y=0;
};

int main()
{
    int N=0,K=0;
    double sum=0;
    Point point;

    cin>>N>>K;
    for(int i=0 ; i<N ; i++)
    {
        Point tempPoint=point;
        cin>>point.X>>point.Y;
        if(i>0)
            sum+=sqrt(pow(tempPoint.X-point.X,2)+pow(tempPoint.Y-point.Y,2));
    }

    cout<<fixed<<setprecision(9)<<K*(sum/50)<<endl;
    return 0;
}
