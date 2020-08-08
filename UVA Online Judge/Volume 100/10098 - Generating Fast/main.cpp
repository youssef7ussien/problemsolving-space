// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
// https://www.techiedelight.com/find-permutations-given-string/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void swapChars(char *a,char *b)
{
    if(a==b)
        return;
    char temp=*a;
    *a=*b;
    *b=temp;
}

void charPermutations(string str, int from, int to,vector<string> &strings)
{
    if(from==to)
        { strings.push_back(str); return; }

    for(int i=from ; i<=to ; i++)
    {
        swapChars(&str[from],&str[i]);
        charPermutations(str, from+1, to, strings);
    }
}

bool pureString(string str)
{
    for(int i=0 ; i<(int)str.size()-1 ; i++)
        if(str[i]!=str[i+1])
            return false;
    return true;
}
vector<string> getAllPermutations(string str)
{
    vector<string> strings;

    if(pureString(str))
        strings.push_back(str);
    else
    {
        sort(str.begin(),str.end());
        charPermutations(str,0,(int)str.size()-1,strings);
    }

    return strings;
}

void printPermutations(vector<string> strings)
{
    map<string,bool> isSaved;
    for(auto it=strings.begin() ; it!=strings.end() ; it++)
        if(!isSaved[*it])
            { cout<<*it<<endl; isSaved[*it]=true; }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    string str;
    while(n--)
    {
        cin>>str;
        printPermutations(getAllPermutations(str));
    }

    return 0;
}
