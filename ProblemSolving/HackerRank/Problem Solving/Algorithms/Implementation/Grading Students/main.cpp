#include <iostream>
using namespace std;
int main()
{
    int grade , num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int temp;
        cin>>grade;
        temp=((grade/5+1)*5)-grade;
        if(temp<3 && grade>37)
            grade+=temp;
        cout<<grade<<endl;
    }

    return 0;
}
