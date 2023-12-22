#include <iostream>

using namespace std;

int main()
{
    int numProblems , trueFalse , ProblemSolved=0 ;
    cin>>numProblems;
    for(int i=0 ; i<numProblems ; i++)
    {
        int numTrue=0 ;
        for(int i=0 ; i<3 ; i++)
        {
            cin>>trueFalse;
            if(trueFalse==1)
                numTrue++;
        }
        if(numTrue>=2)
            ProblemSolved++;
    }
    cout<<ProblemSolved<<endl;
    return 0;
}
