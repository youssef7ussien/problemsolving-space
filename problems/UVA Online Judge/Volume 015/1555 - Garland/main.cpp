/**
* If you change the formula to: "H(i) = ( H(i-1) + H(i+1) ) / 2 - 1" to "H(i) = 2 * H(i-1) - H(i-2) + 2"
* you can see that if we fix the position of the second lamp, all the
* sequence of positions will be fixed.So we just need to find a good position for the second lamp
* so that the position of the last lamp is as low as possible( >= 0).
*
* Now it's not hard to see that binary search will work to find the best position of the second lamp
* from 0 to A(position of the first).
*
* Because if you put it low you'll get a negative value somewhere in the sequence, and of the
* values(real values) that give no negative position, the lowest of them gives the lowest
* position of B(the last lamp).
*
*/

#include <bits/stdc++.h>

using namespace std;
#define EPS ((long double)1e-9)

bool isValid(int N,double A,double B,double &result)
{
    double H3=0;
    for(int i=3 ; i<=N ; i++)
    {
        H3=2.0*B-A+2.0, A=B, B=H3;
        if(H3<0)
            return false;
    }
    result=H3;
    return true;
}

double lowestHeightOfRight(int N,double A)
{
    double left=0, right=A, result=-1;
    while(right-left>EPS)
    {
        double middle=(left+right)/2;
        isValid(N,A,middle,result) ? right=middle : left=middle;

    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int N;  double A;

    while(cin>>N>>A)
        cout<<fixed<<setprecision(2)<<lowestHeightOfRight(N,A)<<"\n";

    return 0;
}
