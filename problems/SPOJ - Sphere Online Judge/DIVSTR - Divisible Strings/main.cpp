#include <iostream>
using namespace std;

int countSubStrings(const string &strX,const string &strY)
{
    int count=0;

    for (int i=0, j=0 ; i<(int)strX.size() ; i++)
    {
        if(strX[i]==strY[j])
        {
            j++;
            if(j==(int)strY.size())
                { count++; j=0; }
        }
    }
    return count;
}

int numberRemoved(const string &strX,const string &strY)
{
    int count=countSubStrings(strX,strY);
    return count==0 ? (int)strX.size() : (strX.size()-count*strY.size());
}

int main()
{
    int T=0;
    cin>>T;
    cin.get();
    for(int i=0 ; i<T ; i++)
    {
        string strX, strY;
        getline(cin,strX);
        getline(cin,strY);
        cout<<numberRemoved(strX,strY)<<endl;
    }

    return 0;
}
