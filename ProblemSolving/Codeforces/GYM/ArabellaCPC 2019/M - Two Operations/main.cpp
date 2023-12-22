#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    vector<int> freq(26,0);
    string str;

    cin>>str;

    for(int i=0 ; i<(int)str.size() ; i++)
        freq[str[i]-'a']++;

    for(int i=0 ; i<(int)freq.size()-1 ; i++) // (size-1) to ignore z
        freq[i+1]+=freq[i]/2, freq[i]%=2;

    for(int i=(int)freq.size()-1 ; i>=0 ; i--)
        for(int j=0 ; j<freq[i] ; j++)
            cout<<(char)(i+'a');
    cout<<endl;

    return 0;
}

