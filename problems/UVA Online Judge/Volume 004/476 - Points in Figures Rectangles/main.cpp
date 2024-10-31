#include <iostream>
#include <vector>

using namespace std;
#define SIZE(v) ((int)v.size())

struct Point {
    double X=0.0,Y=0.0;
};

struct Rectangle {
    Point upperLeft, lowerRight;
};

bool isInRegctangle(const Rectangle &rectangle,const Point &point)
{
    return (point.X > rectangle.upperLeft.X && point.Y < rectangle.upperLeft.Y)
        && (point.X < rectangle.lowerRight.X && point.Y > rectangle.lowerRight.Y);
}

void findPoints(const vector<Rectangle> &rectangles,const vector<Point> &points)
{
    for(int i=0 ; i<SIZE(points) ; i++)
    {
        bool contained=false;
        for(int j=0 ; j<SIZE(rectangles) ; j++)
            if(isInRegctangle(rectangles[j], points[i]))
                contained=true, cout<<"Point "<<i+1<<" is contained in figure "<<j+1<<endl;
        if(!contained)
            cout<<"Point "<<i+1<<" is not contained in any figure"<<endl;
    }
}

int main()
{
    vector<Rectangle> rectangles;
    char type;
    while(cin>>type && type!='*')
    {
        Rectangle rectangle;
        cin>>rectangle.upperLeft.X>>rectangle.upperLeft.Y>>rectangle.lowerRight.X>>rectangle.lowerRight.Y;
        rectangles.push_back(Rectangle(rectangle));
    }

    vector<Point> points;
    Point point;
    while(cin>>point.X>>point.Y && (point.X!=9999.9 && point.Y!=9999.9))
        points.push_back(Point(point));

    findPoints(rectangles, points);

    return 0;
}
