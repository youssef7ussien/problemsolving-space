#include <iostream>
#include <vector>

using namespace std;


int numMoves(vector<int> bookPos)
{
    int counter=0, firstIndex=-1, lastIndex=-1;

    for(int i=0 ; i<(int)bookPos.size()-1 ; i++)
        if(bookPos[i]==1 && bookPos[i+1]!=1)
            { firstIndex=i; break; }
    for(int i=(int)bookPos.size()-1 ; i>0 ; i--)
        if(bookPos[i]==1 && bookPos[i-1]!=1)
            { lastIndex=i; break; }

    if(firstIndex==-1 || lastIndex==-1)
        return 0;

    for(int i=firstIndex ; i<=lastIndex ; i++)
        if(bookPos[i]==0)
            counter++;
    return counter;
}

int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> bookPos(n);
        for(auto &it : bookPos)
            cin>>it;
        cout<<numMoves(bookPos)<<endl;
    }
    return 0;
}
