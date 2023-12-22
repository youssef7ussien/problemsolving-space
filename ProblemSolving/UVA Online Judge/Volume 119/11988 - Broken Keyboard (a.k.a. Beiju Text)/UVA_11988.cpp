/**
 * Title: "Broken Keyboard (a.k.a. Beiju Text)", UVA Online Judge problem. 
 * Date: Sunday, 19 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)     freopen(file, "r", stdin)
#define FILE_OUT(file)    freopen(file, "w", stdout)

int main()
{
    #ifdef DEBUG
        FILE_IN("__UVA_11988_input.txt");
        FILE_OUT("__UVA_11988_output.txt");
    #endif
    
    FAST_IO;
    
    string str;

    while(getline(cin, str))
    {
        list<char> text;
        list<char>::iterator itText = text.begin();
        for(auto &it : str)
        {
            if(it == '[')
                itText = text.begin();
            else if(it == ']')
                itText = text.end();
            else
                text.insert(itText, it);
        }

        for(auto &it : text)
            cout<<it;
        cout<<"\n";
    }
    
    return 0;
}