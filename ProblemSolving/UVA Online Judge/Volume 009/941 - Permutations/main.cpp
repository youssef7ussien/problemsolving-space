#include <iostream>
#include <algorithm>

using namespace std;

typedef long long Long;

Long fact[21];

bool pureString(string str)
{
    for(int i=0 ; i<(int)str.size()-1 ; i++)
        if(str[i]!=str[i+1])
            return false;
    return true;
}

void computeFactorial()
{
    fact[0]=1;
    for(int i=1 ; i<21 ; i++)
        fact[i]=fact[i-1]*i;
}

string getPermutation(string str,Long numPer)
{
    string result="";

    if(pureString(str))
        return str;

    sort(str.begin(),str.end());

    for(int i=str.size()-1 ; i>=0 ; i--)
    {
        Long pos=numPer/fact[i];
        result+=str[pos];
        str.erase(str.begin()+pos);
        numPer%=fact[i];
    }

    return result;
}

int main()
{
    computeFactorial();

    int n;
    cin>>n;

    while(n--)
    {
        string str;
        Long numPer;

        cin>>str>>numPer;
        cout<<getPermutation(str,numPer)<<endl;
    }

    return 0;
}
