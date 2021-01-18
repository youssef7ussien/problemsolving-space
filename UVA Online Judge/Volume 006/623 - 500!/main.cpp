#include <iostream>

using namespace std;

#define MAX 2569 // The number of digits in a factorial of 1000 is 2568

void printBigInt(int num,int start,const int bigNum[])
{
    cout<<num<<"!"<<endl;
    for(int i=start-1 ; i>=0 ; i--)
        cout<<bigNum[i];
    cout<<endl;
}

void multiplyBigInt(int numFact,int fact[],int &length)
{
    int carry=0;

    for(int i=0  ; i<length ; i++)
    {
        int prod=fact[i]*numFact+carry;
        fact[i]=prod%10;
        carry=prod/10;
    }

    while(carry)
    {
        fact[length++]=carry%10;
        carry/=10;
    }
}

void factorialBigInt(int num)
{
    int *fact;
    if(num==0 || num==1)
    {
        fact=new int[1]{1};
        printBigInt(num,1,fact);
        return;
    }

    fact=new int[MAX];
    int length=1;
    fact[0]=1;

    for(int i=2 ; i<=num ; i++)
        multiplyBigInt(i,fact,length);

    printBigInt(num,length,fact);
}

int main()
{
	int num;

	while(cin>>num)
		factorialBigInt(num);

	return 0;
}
