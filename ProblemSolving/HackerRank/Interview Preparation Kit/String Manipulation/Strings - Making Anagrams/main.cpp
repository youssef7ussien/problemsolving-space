#include <iostream>
#include <vector>
using namespace std;

vector<int> frequency(const string &strA,const string &strB)
{
    vector<int> freq(26,0); int i=0;

    while(i<(int)strA.size() || i<(int)strB.size())
    {
        if(i<(int)strA.size())
            freq[strA[i]-'a']++;
        if(i<(int)strB.size())
            freq[strB[i]-'a']--;
        i++;
    }

    return freq;
}

int countAsymmetricChar(const vector<int> freq)
{
    int counter=0;
    for(auto it : freq)
        counter+=abs(it);
    return counter;
}

int main()
{
    string strA,strB;
    cin>>strA>>strB;

    cout<<countAsymmetricChar(frequency(strA,strB))<<endl;
    return 0;
}
