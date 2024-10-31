#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int GCD(int a,int b)
{
    if(b==0)
        return a;
    return GCD(b,a%b);
}

// Another solution
/*
bool isValid(const int &step,const int &mod)
{
    int seed=0;
    map<int,bool> visited;

    for(int i=0 ; i<mod-1 ; i++)
    {
        seed=(seed+step)%mod;
        if(visited[seed])
            return false;
        visited[seed]=true;
    }

    return true;
}*/

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int step, mod;
    while(cin>>step>>mod)
    {
        cout<<right<<setw(10)<<step<<setw(10)<<mod<<"    ";
        GCD(step,mod)==1 ? cout<<"Good Choice\n\n" : cout<<"Bad Choice\n\n"; // Solution accepted
//        isValid(step,mod) ? cout<<"Good Choice\n\n" : cout<<"Bad Choice\n\n"; // Another solution accepted
    }

    return 0;
}
