#include <iostream>

using namespace std;

int main()
{
    int teams=0 , result=0 ;
    cin>>teams;
    int home[teams] , guest[teams] ;
    for (int i=0 ; i<teams ; i++)
        cin>>home[i]>>guest[i];
    for (int i=0 ; i<teams ; i++)
    {
        for (int j=0 ; j<teams ; j++)
            if (home[i]==guest[j]) result++;
    }
    cout<<result<<endl;

    return 0;
}
