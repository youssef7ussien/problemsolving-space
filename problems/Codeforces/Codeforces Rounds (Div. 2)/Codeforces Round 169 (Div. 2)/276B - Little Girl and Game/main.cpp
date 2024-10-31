#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string str;
    vector<int> freq(26);
    int counter=0;

    cin>>str;

    for(auto &it : str)
        freq[it - 'a']++;

    for(auto &it : freq)
        counter+=(it % 2 != 0);

    cout<<(counter==0 || counter%2!=0 ? "First" : "Second")<<"\n";

    return 0;
}
