/**
 * Title: "Two-gram", Codeforces problem. 
 * Date: Monday, 15 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    int N;
    string str;
    cin>>N>>str;

    map<string, int> freq;
    for(int i = 0 ; i < N - 1 ; i++)
        freq[string(1, str[i]) + str[i + 1]]++;
    
    auto comp = [](const pair<string, int> &a, const pair<string, int> &b){ return a.second < b.second; };

    cout<<max_element(ALL(freq), comp)->first<<"\n";
    return 0;
}