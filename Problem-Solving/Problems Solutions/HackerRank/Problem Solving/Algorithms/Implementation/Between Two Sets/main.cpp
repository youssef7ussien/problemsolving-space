#include <iostream>
#include <vector>

using namespace std;

int GCD(int a,int b)
{
    while (b>0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int findGCD(const vector<int>&set1 ,int n)
{
    int number=set1[0];
    for(int i=1;i<n;i++)
        number=GCD(number,set1[i]);
    return number;
}
int LCM(int a,int b)
{
    return (a*(b/GCD(a,b)));
}
int findLCM(const vector<int>&set1 ,int n)
{
    int number=set1[0];
    for(int i=1;i<n;i++)
        number=LCM(number,set1[i]);
    return number;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>set1(n),set2(m);
    for(int i=0;i<n;i++)
        cin>>set1[i];
    for(int i=0;i<m;i++)
        cin>>set2[i];
    int numLCM=findLCM(set1,n),numGCD=findGCD(set2,m),counter=0;
    cout<<numLCM<<"  "<<numGCD<<endl;
    for(int i=numLCM ;i<=numGCD ;i+=numLCM)
    { if(numGCD%i==0) counter++; }
    cout<<counter<<endl;
    return 0;
}

