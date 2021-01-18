// graph BFS
#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Square {
    char column; int row;

    bool isValid() const {
        return (row>=1 && row<=8 && column>='a' && column<='h');
    }

    bool operator ==(const Square &square) const {
        return (this->column==square.column && this->row==square.row);
    }

     bool operator <(const Square &square)  const {
        return row<square.row || (row==square.row && column<square.column);
    }
};

int minMoves(const Square &start,const Square &destination)
{
    // Top-Right, Top-Left, Right-Top, Right-bottom, Left-Top, Left-Bottom, Bottom-Right, Bottom-Left
    const int direction[][2]={{1,2},{-1,2},{2,1},{2,-1},{-2,1},{-2,-1},{1,-2},{-1,-2}};
    queue<Square> que;
    map<Square,int> lengths;

    que.push(start);
    while(que.size())
    {
        Square current=que.front();
        que.pop();

        if(current==destination) return lengths[current];

        for(int i=0 ; i<8 ; i++)
        {
            Square newSquare={(char)(current.column+direction[i][0]),current.row+direction[i][1]};
            if(lengths[newSquare]==0 && newSquare.isValid())
                lengths[newSquare]=lengths[current]+1, que.push(newSquare);
        }
    }
    return 0;
}

int main()
{
    Square start, destination;
    while(cin>>start.column>>start.row>>destination.column>>destination.row)
        cout<<"To get from "<<start.column<<start.row<<" to "<<destination.column<<destination.row
            <<" takes "<<minMoves(start,destination)<<" knight moves."<<endl;
    return 0;
}
