/**
 * Title: "Andy's First Dictionary", UVA Online Judge problem. 
 * Date: Wednesday, 16 February 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)               freopen(file, "r", stdin)
#define FILE_OUT(file)              freopen(file, "w", stdout)


set<string> validWord(const string &str) {
    string newStr;
    set<string> words;
    for(const auto &it : str) {
        if(it >= 'A' && it <= 'Z')
            newStr += it + 32;
        else if(it >= 'a' && it <= 'z')
            newStr += it;
        else if(!newStr.empty())
            words.insert(newStr), newStr = "";
    }
    if(!newStr.empty())
        words.insert(newStr);

    return words;
}

int main()
{
    #ifdef __DEBUG
        FILE_IN("samples\\__UVA_10815.in");
        FILE_OUT("samples\\__UVA_10815.out");
    #endif
    
    FAST_IO;
    
    string str;
    set<string> words;
    while(cin>>str) {
        set<string> newWords = validWord(str);
        words.insert(ALL(newWords));
    }

    for(auto &it : words)
        cout<<it<<"\n";
    
    return 0;
}