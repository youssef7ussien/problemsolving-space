#include <iostream>
using namespace std;

#define NUM(n) (n-'0')

int main()
{
    string num;
    cin>>num;

    int down=NUM(num[0]), up=11-NUM(num[0]);
    for(int i=1 ; i<(int)num.size() ; i++)
    {
        int temp=down;
        down=min(NUM(num[i])+down, up+NUM(num[i]));
        up=min((11-NUM(num[i]))+temp, 10-NUM(num[i])+(up-1));
    }

    cout<<min(up,down)<<endl;
    return 0;
}
