#include <iostream>

using namespace std;
#define formula(n) (n*(n+1)/2)

bool checkIsValid(int num)
{
    int left=1, right=num;

    while(left<=right)
    {
        int middle=(left+right)/2;

        if(formula(middle) == num)
            return true;

        formula(middle) < num ? left=middle+1 : right=middle-1;
    }

    return false;
}

int main()
{
    int num;
    cin>>num;

    cout<<(checkIsValid(num) ? "YES" : "NO")<<"\n";


    return 0;
}
