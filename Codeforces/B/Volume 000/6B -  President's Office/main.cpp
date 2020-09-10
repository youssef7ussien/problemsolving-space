#include <iostream>

using namespace std;

int row,column;
bool insideBorder(int gotoX, int gotoY)
{
	return (gotoX>-1 && gotoX<row) && (gotoY>-1 && gotoY<column);
}
int main()
{
    int direction[4][2]={{-1,0},{1,0},{0,-1},{0,1}},counter=0;
    char color;
    bool character[26]={false};
    cin>>row>>column>>color;

    char **room=new char*[row];
    for(int i=0;i<row;i++)
        room[i]=new char[column];
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
        {
            cin>>room[i][j];
            if(room[i][j]==color)
                counter++;
        }
    if(counter==0)
    { cout<<"0"<<endl; return 0; }
    else
        counter=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            if(room[i][j]==color)
                for(int n=0;n<4;n++)
                {
                    int gotoX=i+direction[n][0];
                    int gotoY=j+direction[n][1];
                    if(insideBorder(gotoX,gotoY) && room[gotoX][gotoY]!=color
                       && room[gotoX][gotoY]!='.' && !character[room[gotoX][gotoY]-'A'])
                    {
                        character[room[gotoX][gotoY]-'A']=true;
                        counter++;
                    }
                }
    }
    cout<<counter<<endl;

    for(int i=0; i<row ; i++)
        delete [] room[i];
    delete [] room;
    return 0;
}
