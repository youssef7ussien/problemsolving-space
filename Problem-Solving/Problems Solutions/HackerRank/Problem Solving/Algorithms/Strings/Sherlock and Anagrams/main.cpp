#include <iostream>
#include<algorithm>
#include<map>
using namespace std;

int checkAnagrams(string str)
{
    map<string,int> substrings;
    for(int i=0 ; i<str.size() ; i++)
        for(int j=1 ; j+i<=str.size() ; j++)
        {
            string sub=str.substr(i,j);
            sort(sub.begin(),sub.end());
            substrings[sub]++;
        }

    int counter=0;
    for (auto it=substrings.begin() ; it!=substrings.end(); it++)
        counter+=it->second*(it->second-1)/2; // -> (it->second) Combinations 2

    return counter;
}

int main()
{
    int number;
    cin>>number;
    for(int i=0 ; i<number ; i++)
    {
        string str;
        cin>>str;
        cout<<checkAnagrams(str)<<endl;
    }
    return 0;
}
