#include <iostream>

using namespace std;

struct Point{
    long long X=0,Y=0;
};

int minTime(const Point &point1,const Point &point2)
{
    return point1.X==point2.X || point1.Y==point2.Y ?
        abs(point1.X-point2.X+point1.Y-point2.Y) : 2+abs(point1.X-point2.X)+abs(point1.Y-point2.Y);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Point point1,point2;
        cin>>point1.X>>point1.Y>>point2.X>>point2.Y;
        cout<<minTime(point1,point2)<<endl;
    }
    return 0;
}
