#include <iostream>

using namespace std;

int main()
{
    int numGroups , studentGroup[5]={0} , numStudent , numTaxi=0 ;
    cin>>numGroups;
    for(int i=0 ; i<numGroups ;i++)
    {
        cin>>numStudent;
        studentGroup[numStudent]++;
    }
    numTaxi=studentGroup[4];

    while (studentGroup[3]!=0 && studentGroup[1]!=0)
    { numTaxi++;  studentGroup[3]--;  studentGroup[1]--; }

    if(studentGroup[2]>1)
    {
        while (studentGroup[2]>1)
        { numTaxi++;  studentGroup[2]-=2; }
    }

    while (studentGroup[2]!=0 && studentGroup[1]!=0)
    { numTaxi++;  studentGroup[2]--;  studentGroup[1]-=2; }

    if(studentGroup[1]==0 && studentGroup[3]!=0 )
        numTaxi+=studentGroup[3];

    if(studentGroup[1]==0 && studentGroup[2]!=0 )
        numTaxi+=studentGroup[2];

    if(studentGroup[1]!=0)
        while (studentGroup[1]>0)
        { numTaxi++;  studentGroup[1]-=4; }

    cout<<numTaxi<<endl;

    return 0;
}
