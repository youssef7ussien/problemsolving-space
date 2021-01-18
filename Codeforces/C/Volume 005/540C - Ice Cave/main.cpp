#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Point {
    int X,Y;

    bool isValid(const int &N,const int &M) const {
        return (X>=0 && X<N && Y>=0 && Y<M);
    }

    void operator --() {
        this->X--, this->Y--;
    }

    bool operator ==(const Point &point) const {
        return (this->X==point.X && this->Y==point.Y );
    }

    bool operator <(const Point &point)  const {
        return X<point.X || (X==point.X && Y<point.Y);
    }
};

string isReachDestination(const int &N,const int &M,Point start,Point destination,map<Point,char> &points)
{
        // East, West, South, North
    const Point direction[]={{1,0},{-1,0},{0,1},{0,-1}};
    queue<Point> que;

    --start, --destination, que.push(start);
    while(que.size())
    {
        Point currentPoint=que.front();
        que.pop();

        for(int i=0 ; i<4 ; i++)
        {
            Point newPoint={currentPoint.X+direction[i].X,currentPoint.Y+direction[i].Y};
            if(!newPoint.isValid(N,M))
                continue;

            if(newPoint==destination && points[destination]=='X')
                return "YES";

            if(points[newPoint]=='.')
                points[newPoint]='X', que.push(newPoint);
        }
    }

    return "NO";
}

int main()
{
    int N,M;
    cin>>N>>M;

    map<Point,char> points;
    for(int i=0 ; i<N ; i++)
        for(int j=0 ; j<M ; j++)
        {
            char ice;
            cin>>ice;
            points[{i,j}]=ice;
        }

    Point start,destination;
    cin>>start.X>>start.Y>>destination.X>>destination.Y;

    cout<<isReachDestination(N,M,start,destination,points)<<endl;

    return 0;
}
