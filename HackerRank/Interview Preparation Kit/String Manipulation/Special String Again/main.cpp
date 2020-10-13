// Explain the solution: https://www.geeksforgeeks.org/count-special-palindromes-in-a-string/
#include <iostream>
#include <vector>

using namespace std;

int countSubstringSameChar(const string &str,vector<int> &sameChar)
{
    int counter=1,result=0,left=0,right=1;

    while(right<(int)str.size())
    {
        if(str[left]==str[right])
            counter++;
        else
        {
            result+=counter*(counter+1)/2;
            sameChar[left]=counter;
            left=right;
            counter=1;
        }
        right++;
    }

    sameChar[left]=counter;
    return result+counter*(counter+1)/2;
}

int countSubstringMiddle(const string &str,vector<int> &sameChar)
{
    int counter=0;

    for(int i=1; i<(int)str.size() ; i++)
    {
        if(str[i]==str[i-1])
            sameChar[i]=sameChar[i-1];
        if(str[i-1]==str[i+1] && str[i]!=str[i-1])
            counter+=min(sameChar[i-1],sameChar[i+1]);
    }

    return counter;
}

int countSpecialSubstrings(string str)
{
    vector<int> sameChar(str.size());

    // You must call countSubstringSameChar first because countSubstringMiddle depend on them.
    return countSubstringSameChar(str,sameChar)+countSubstringMiddle(str,sameChar);

}

int main()
{
    string str;
    cin>>str>>str;

    cout<<countSpecialSubstrings(str)<<endl;
    return 0;
}
