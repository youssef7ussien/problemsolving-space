#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int matrix[5][5] , row , column ;
    for(int i=0 ; i<5 ; i++)
         for(int j=0 ; j<5 ; j++)
         {
            cin>>matrix[i][j];
            if(matrix[i][j]==1)
            { row=3-(i+1); column=3-(j+1); }
         }
    cout<<abs(row)+abs(column);
    return 0;
}
