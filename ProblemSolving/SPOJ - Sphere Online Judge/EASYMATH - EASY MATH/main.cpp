/**
 * To understand how to solve a problem:
 * https://www.youtube.com/watch?v=sr6WgCLcgVM&list=PLPt2dINI2MIY7l5zyFd1W28rei3b-AXaJ&index=15&t=0s
 */
#include <iostream>
using namespace std;
typedef long long Long;

Long GCD(Long a, Long b)
{
	if (a==0)
        return b;
	return GCD(b%a,a);
}

Long LCM(Long a, Long b)
{
	return (a*b)/GCD(a,b);
}

int nums[5];
void initNums(Long a,Long d)
{
    for(int i=0 ; i<5 ; i++)
        nums[i]=a+i*d;
}

Long counterNumbers(const Long &range,int index=0,Long c=1,int sign=1)
{
    if(index==5)
        return sign*range/c;

    return counterNumbers(range,index+1,c,sign)+counterNumbers(range,index+1,LCM(c,nums[index]),sign*-1);
}

int main()
{
    int s=1;
    cin>>s;
    for(int i=0 ;i<s ; i++)
    {
        Long n,m,a,d;
        cin>>n>>m>>a>>d;
        initNums(a,d);
        cout<<counterNumbers(m)-counterNumbers(n-1)<<endl;
    }

    return 0;
}
