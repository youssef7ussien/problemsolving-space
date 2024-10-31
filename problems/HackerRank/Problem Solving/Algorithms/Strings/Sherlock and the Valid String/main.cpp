#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 26

string isValid(string str)
{
    vector<int> freq(MAX,0);
    for(int i=0 ; i<(int)str.size() ; i++)
        freq[str[i]-'a']++;

    sort(freq.begin(),freq.end());

    int index=0;
    while(freq[index]==0)
        index++;

    if(    (freq[MAX-1]==freq[index])
        || (freq[MAX-1]-freq[index]==1 && freq[MAX-1]>freq[MAX-2])
        || (freq[index]==1 && freq[index+1]==freq[MAX-1]) )
        return "YES";

    return "NO";
}

int main()
{
    string str;
    cin>>str;
    cout<<isValid(str)<<endl;

    return 0;
}
