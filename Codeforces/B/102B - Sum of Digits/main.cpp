#include <iostream>

using namespace std;

int sumOfDigit(int number)
{
    int cpyNumber=0;
    while(number>0)
    {
        cpyNumber+=number%10;
        number/=10;
    }
    return cpyNumber;
}
int main()
{
    int counter=0,number=0;
    string str;
    cin>>str;
    if(str.size()>1)
    {
        for(int i=0;i<str.size();i++)
            number+=str[i]-'0';
        counter=1;
        while(number>9)
        {
            number=sumOfDigit(number);
            counter++;
        }
    }
    cout<<counter<<endl;
    return 0;
}
