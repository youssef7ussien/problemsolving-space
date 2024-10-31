#include <iostream>

using namespace std;

int main()
{
    int primes[]={2,3,4,5,7,9,11,13,17,19,23,25,29,31,37,41,43,47,49,51};
    int counter=0;

    for(int i=0 ; i<20 ; i++)
    {
        cout<<primes[i]<<"\n"; fflush(stdout);
        string input;
        cin>>input;
        counter+=(input=="yes");
        if(counter>=2)
            break;
    }

    counter<2 ? cout<<"prime\n" : cout<<"composite\n";

    return 0;
}
