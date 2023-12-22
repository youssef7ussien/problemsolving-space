// hint: https://www.geeksforgeeks.org/find-missing-point-parallelogram/
#include <iostream>
#include <iomanip>
using namespace std;

struct Point {
    double X=0.0,Y=0.0;

    bool operator ==(const Point &point) const
    {
        return (X==point.X && Y==point.Y);
    }
};

void printFourthPoint(const Point &first,const Point &second,const Point &third)
{
    cout<<fixed<<setprecision(3)<<(first.X+second.X-third.X)<<" "<<(first.Y+second.Y-third.Y)<<endl;
}

int main()
{
    pair<Point,Point> firstSide, secondSide;

    while(cin>>firstSide.first.X>>firstSide.first.Y>>firstSide.second.X>>firstSide.second.Y
            >>secondSide.first.X>>secondSide.first.Y>>secondSide.second.X>>secondSide.second.Y)
    {

        if(firstSide.first == secondSide.first)
            printFourthPoint(firstSide.second,secondSide.second,firstSide.first);
        else if(firstSide.first == secondSide.second)
            printFourthPoint(firstSide.second,secondSide.first,firstSide.first);
        else if(firstSide.second == secondSide.first)
            printFourthPoint(firstSide.first,secondSide.second,firstSide.second);
        else
            printFourthPoint(firstSide.first,secondSide.first,firstSide.second);
    }

    return 0;
}
