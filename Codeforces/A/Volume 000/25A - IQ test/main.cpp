#include <iostream>

using namespace std;

int main()
{
    int numbers , input , similar=0 , evenPlace=0 , oddPlace=0 ;
    cin>>input;
    for(int i=1 ; i<=input ; i++)
    {
        cin>>numbers;
        if(numbers%2==0)
            { similar++; evenPlace=i; }
        else
             oddPlace=i;
    }
    if(similar==1)
        cout<<evenPlace<<endl;
    else
        cout<<oddPlace<<endl;
    return 0;
}
