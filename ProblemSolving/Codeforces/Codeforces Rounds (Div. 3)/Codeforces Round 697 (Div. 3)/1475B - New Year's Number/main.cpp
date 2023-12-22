#include <iostream>

using namespace std;

bool isValidNum(int num) // Another solution
{
    if(num<2020)
        return false;

    for(int i=0 ; i*2020<=num ; i++)
        if((num-i*2020)%2021==0)
            return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int num;
        cin>>num;

        (num/2020)>=(num%2020) ? cout<<"YES\n" : cout<<"NO\n"; // Solution accepted
        // isValidNum(num) ? cout<<"YES\n" : cout<<"NO\n"; // Another solution accepted
    }

    return 0;
}
