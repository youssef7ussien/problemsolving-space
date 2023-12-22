/**
 * Title: "Complete the Word", Codeforces problem. 
 * Date: Friday, 04 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;


inline int nextZero(const VI &freq, int current) {
    while(freq[current] > 0) current++;
    return current;
}

string replaceAll(string str, VI freq, PII range)
{
    int current = nextZero(freq, 0);
    for(int i = range.first ; i < range.second ; i++)
        if(str[i] == '?') {
            str[i] = 'A' + current;
            current = nextZero(freq, current+1);
        }

    for(auto &it : str)
        if(it == '?') 
            it = 'A';

    return str;
}

int main()
{
    FAST_IO;
    
    string str;
    cin>>str;
    
    if(SIZE(str) < 26) {
        cout<<-1<<"\n";
        return 0;
    }

    VI freq(26);
    int counter = 0;
    for(int i=0 ; i<26 ; i++) {
        if(str[i] != '?') {
            freq[str[i] - 'A']++;
            counter += (freq[str[i] - 'A'] == 1);
        }
        else
            counter++;
    }

    if(counter == 26) {
        cout<<replaceAll(str, freq, {0, 26})<<"\n";
        return 0;
    }
    
    for(int i=26 ; i < SIZE(str) ; i++) {
        if(str[i] == '?')
            counter++;
        else if(str[i] != '?')
            freq[str[i] - 'A']++, counter += (freq[str[i] - 'A'] == 1);

        if(str[i - 26] == '?') 
            counter--;
        else if(str[i - 26] != '?')
            freq[str[i - 26] - 'A']--, counter -= (freq[str[i - 26] - 'A'] == 0);
        
        if(counter == 26) {
            cout<<replaceAll(str, freq, {i - 25, i+1})<<"\n";
            return 0;
        }
    }

    cout<<-1<<"\n";
    return 0;
}