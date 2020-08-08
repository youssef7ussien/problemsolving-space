#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 10001

void LastDigitInFact(int *data)
{
    long long fact=1;
    data[0]=1;
    for(int i=1 ; i<=MAX ; i++)
    {
        fact*=i;
        while(fact%10==0)
             fact/=10;
        fact%=1000000;
        data[i]=fact%10;
    }
}

/**
 *      Another solution
 *
 *      https://math.stackexchange.com/questions/130352/last-non-zero-digit-of-a-factorial
 *
 * int firstDigits[]={1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
 * int lastNonZeroDigit(int num)
 * {
 *
 *     if(n<10)
 *         return firstDigits[num];
 *
 *     if(((n/10)%10)%2 == 0)
 *         return (6*lastNonZeroDigit(num/5)*firstDigits[num%10])%10;
 *
 *     return (4*lastNonZeroDigit(num/5)*firstDigits[num%10]) % 10;
 * }
 *
 *
 */

int main()
{
    int data[MAX];
    int num;
    LastDigitInFact(data);

    while(cin>>num)
        cout<<setw(5)<<num<<" -> "<<data[num]<<endl;

    return 0;
}
