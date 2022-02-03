#include <iostream>
#include <vector>

using namespace std;

int numberWays(const vector<int> &squares, int days, int mounth)
{
    vector<int> sum(squares.size()+1,0);

    for(int i=1 ; i<=(int)squares.size() ; i++)
        sum[i]=sum[i-1]+squares[i-1];

    int count=0;
    for(int i=mounth ; i<sum.size() ; i++)
        if(sum[i]-sum[i-mounth]==days)
            count++;

    return count;
}

int main()
{
    int n,m,d;
    cin>>n;

    vector<int> squares(n);
    for(int i=0 ; i<n ; i++)
        cin>>squares[i];

    cin>>d>>m;

    cout<<numberWays(squares,d,m)<<endl;
    return 0;
}
