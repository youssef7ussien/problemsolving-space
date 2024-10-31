#include <iostream>
using namespace std;

int main()
{
    string names[3]={"Carrots","Kiwis","Grapes"};
    int width,numWaste,numQueries;
    cin>>width>>width>>numWaste>>numQueries;
    int wastecells[numWaste][2];
    for(int i=0 ; i<numWaste ; i++)
    {
        int cellX,cellY;
        cin>>cellX>>cellY;
        wastecells[i][0]=cellX-1;
        wastecells[i][1]=cellY-1;
    }
    for(int i=0 ; i<numQueries ; i++)
    {
        int cellX,cellY;
        cin>>cellX>>cellY;
        cellX--; cellY--;
        int reqCell=cellX*width+cellY;

        for(int j=0 ; j<numWaste ; j++)
        {
            if(cellX==wastecells[j][0] && cellY==wastecells[j][1])
            { reqCell=-1; break; }
            else if(cellX>wastecells[j][0] || (cellX==wastecells[j][0] && cellY>wastecells[j][1]))
                reqCell--;
        }
		if(reqCell==-1)  cout<<"Waste"<<endl;
        else             cout<<names[reqCell%3]<<endl;
    }
    return 0;
}
