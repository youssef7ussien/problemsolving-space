#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string,int>requests;
    int numReq;
    cin>>numReq;
    for(int i=0;i<numReq;i++)
    {
        string str; cin>>str;
        requests[str]?  cout<<str<<requests[str]<<endl : cout<<"OK"<<endl;
        requests[str]++;
    }
    requests.clear();
    return 0;
}
