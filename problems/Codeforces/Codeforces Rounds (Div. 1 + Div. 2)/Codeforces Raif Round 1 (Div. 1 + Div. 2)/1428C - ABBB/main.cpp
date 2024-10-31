#include <iostream>
using namespace std;

int slove(const string &str)
{
    int counter=0;
    for(auto it : str)
        it=='B' && counter!=0 ? counter-- : counter++;
    return counter;
}

int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        string str;
        cin>>str;
        cout<<slove(str)<<endl;
    }
    return 0;
}
