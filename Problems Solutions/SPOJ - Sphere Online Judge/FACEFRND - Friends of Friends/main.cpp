#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N;
    cin>>N;
    map<int,int> friends;
    for(int i=0 ; i<N ; i++)
    {
        int M;
        cin>>M;
        friends[M]=-1;
        cin>>M;
        for(int j=0 ; j<M ; j++)
        {
            int temp;
            cin>>temp;
            if(friends[temp]!=-1)
                friends[temp]++;
        }

    }

    int counter=0;
    for(auto it : friends)
        if(it.second!=-1)
            counter++;

    cout<<counter<<endl;
    return 0;
}
