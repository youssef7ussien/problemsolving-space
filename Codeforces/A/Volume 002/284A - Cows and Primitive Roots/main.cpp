// To understand the problem go to: https://en.wikipedia.org/wiki/Primitive_root_modulo_n
// or https://www.geeksforgeeks.org/find-the-number-of-primitive-roots-modulo-prime/
// and https://www.geeksforgeeks.org/eulers-totient-function/

#include <iostream>
using namespace std;

// GCD : Greatest Common Divisor
int GCD(int a,int b)
{
    if(b==0)
        return a;
    return GCD(b,a%b);
}

int countPrimitiveRoots(int num)
{
    int counter=1;
    num-=1;
    for(int i=2 ; i<num ; i++)
       if(GCD(num,i)==1)
            counter++;

    return counter;
}

int main()
{
    int num;
    cin>>num;
    cout<<countPrimitiveRoots(num)<<endl;
    return 0;
}
