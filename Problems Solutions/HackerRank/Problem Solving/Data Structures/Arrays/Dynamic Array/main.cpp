#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,Q,lastAnswer=0;
    cin>>N>>Q;
    vector<vector<int>> seqList(N);

    for(int i=0 ;i<Q ; i++)
    {
        int quaryType,x,y;
        cin>>quaryType>>x>>y;
        int posSeq=(x^lastAnswer)%N;

        if(quaryType==1)
            seqList[posSeq].push_back(y);
        else
        {
            y=y%((int)seqList[posSeq].size());
            lastAnswer=seqList[posSeq][y];
            cout<<lastAnswer<<endl;
        }
    }

    return 0;
}
