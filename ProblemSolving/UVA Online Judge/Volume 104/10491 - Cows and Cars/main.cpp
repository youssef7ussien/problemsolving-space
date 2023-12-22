#include <iostream>
#include <iomanip>

using namespace std;
#define DIV(D1,D2) ((double)D1/D2)

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int NCOWS, NCARS, NSHOW;
    while(cin>>NCOWS>>NCARS>>NSHOW)
        cout<<fixed<<setprecision(5)
            <<DIV(DIV(NCARS, (NCOWS+NCARS)), DIV((NCOWS+NCARS-NSHOW-1), (NCOWS+NCARS-1)))<<"\n";

    return 0;
}
