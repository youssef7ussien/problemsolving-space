#include <iostream>
using namespace std;

struct Window {
    struct Point {
        int X=0,Y=0;
    } lowerLeft,upperRight;

    bool isDegenerate() const
    {
        return lowerLeft.X >= upperRight.X || lowerLeft.Y >= upperRight.Y;
    }
};

void printPoints(const Window &window)
{
    if(window.isDegenerate())
        cout<<"No Overlap"<<endl;
    else
        cout<<window.lowerLeft.X<<" "<<window.lowerLeft.Y
            <<" "<<window.upperRight.X<<" "<<window.upperRight.Y<<endl;
}

void findNewWindow(const Window &first,const Window &second)
{
    Window newWindow;
    newWindow.lowerLeft.X=max(first.lowerLeft.X,second.lowerLeft.X);
    newWindow.lowerLeft.Y=max(first.lowerLeft.Y,second.lowerLeft.Y);
    newWindow.upperRight.X=min(first.upperRight.X,second.upperRight.X);
    newWindow.upperRight.Y=min(first.upperRight.Y,second.upperRight.Y);

    printPoints(newWindow);
}

int main()
{
    int N=0;
    cin>>N;
    for(int i=0 ; i<N ; i++)
    {
        Window first,second;
        cin>>first.lowerLeft.X>>first.lowerLeft.Y
            >>first.upperRight.X>>first.upperRight.Y;
        cin>>second.lowerLeft.X>>second.lowerLeft.Y
            >>second.upperRight.X>>second.upperRight.Y;

        if(i!=0)
            cout<<endl;
        findNewWindow(first,second);
    }

    return 0;
}
