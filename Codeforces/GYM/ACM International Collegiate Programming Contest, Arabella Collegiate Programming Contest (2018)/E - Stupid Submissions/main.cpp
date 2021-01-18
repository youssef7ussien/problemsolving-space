#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T=0;
    cin>>T;
    while(T--)
    {
        int N=0,M=0,K=0;
        cin>>N>>M>>K;

        vector<char> testCases(N);
        int counter=0,lastVisible=K-1;
        bool accepted=false;

        for(int i=0 ; i<N ; i++)
            cin>>testCases[i];

        while(M--)
        {
            pair<char,int> submit;
            cin>>submit.first;

            if(submit.first=='A')
            {
                accepted=true;
                continue;
            }

            cin>>submit.second;

            if((accepted && testCases[submit.second-1]=='S')
               || (!accepted && testCases[submit.second-1]=='S' && submit.second-1<=lastVisible))
                counter++;

            lastVisible=max(lastVisible,submit.second-1);
        }
        cout<<counter<<endl;
    }
    return 0;
}
