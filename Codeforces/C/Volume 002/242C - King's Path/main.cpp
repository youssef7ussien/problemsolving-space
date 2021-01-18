#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Point {
    long long X,Y;

    bool isValid() const {
        return (X>=0 && X<=1e9 && Y>=0 && Y<=1e9);
    }

    bool operator ==(const Point &point) const {
        return (this->X==point.X && this->Y==point.Y);
    }

     bool operator <(const Point &point)  const {
        return X<point.X || (X==point.X && Y<point.Y);
    }
};


int minMoves(const Point &start,const Point &destination,map<Point,int> &points)
{
        // East, West, South, North, South-East, North-West, North-East, North-West
    const Point direction[8]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    queue<Point> que;
    map<Point, int> lengths;

    que.push(start);
    while(que.size())
    {
        Point currentPoint=que.front();
        que.pop();

        if(currentPoint==destination) return lengths[currentPoint];
        for(int i=0 ; i<8 ; i++)
        {
            Point newPoint={currentPoint.X+direction[i].X, currentPoint.Y+direction[i].Y};
            if(points[newPoint] && lengths[newPoint]==0 && newPoint.isValid())
                lengths[newPoint]=lengths[currentPoint]+1, que.push(newPoint);
        }
    }
    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    Point start,destination;
    int N;
    cin>>start.X>>start.Y>>destination.X>>destination.Y>>N;

    map<Point,int> points;
    for(int i=0 ; i<N ; i++)
    {
        int r, a, b;
        cin>>r>>a>>b;
        for(int j=a ; j<=b ; j++)
            points[{r,j}]=true;
    }

    cout<<minMoves(start,destination,points)<<endl;

    return 0;
}
