/**
 * Title: "Word Index", UVA Online Judge problem. 
 * Date: Saturday, 29 January 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)           ((int)((v).size()))
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)     freopen(file, "r", stdin)
#define FILE_OUT(file)    freopen(file, "w", stdout)

typedef long long         Long;
typedef pair<int, int>    PII;
typedef vector<int>       VI;


void generateAll(unordered_map<string, int> &strings)
{
    char str[6] = "";
    int counter = 1;

    str[1] = '\0';
    for(str[0]='a' ; str[0] <= 'z' ; str[0]++)
        strings[str] = counter++;
    
    str[2] = '\0';
    for(str[0]='a' ; str[0] <= 'z' ; str[0]++)
        for(str[1]=str[0]+1 ; str[1] <= 'z' ; str[1]++)
            strings[str] = counter++;

    str[3] = '\0';
    for(str[0]='a' ; str[0] <= 'z' ; str[0]++)
        for(str[1]=str[0]+1 ; str[1] <= 'z' ; str[1]++)
            for(str[2]=str[1]+1 ; str[2] <= 'z' ; str[2]++)
                strings[str] = counter++;    
    
    str[4] = '\0';
    for(str[0]='a' ; str[0] <= 'z' ; str[0]++)
        for(str[1]=str[0]+1 ; str[1] <= 'z' ; str[1]++)
            for(str[2]=str[1]+1 ; str[2] <= 'z' ; str[2]++)
                for(str[3]=str[2]+1 ; str[3] <= 'z' ; str[3]++)
                    strings[str] = counter++;
                    
    str[5] = '\0';
    for(str[0]='a' ; str[0] <= 'z' ; str[0]++)
        for(str[1]=str[0]+1 ; str[1] <= 'z' ; str[1]++)
            for(str[2]=str[1]+1 ; str[2] <= 'z' ; str[2]++)
                for(str[3]=str[2]+1 ; str[3] <= 'z' ; str[3]++)
                    for(str[4]=str[3]+1 ; str[4] <= 'z' ; str[4]++)
                        strings[str] = counter++;
}

void generateAllBFS(unordered_map<string, int> &strings)
{
    queue<string> Q;
    for (char c = 'a'; c <= 'z'; c++)
        Q.push(string(1, c));

    string s;
    int cont = 1;
    while (!Q.empty()) {
        s = Q.front(), Q.pop();
        strings[s] = cont++;

        if (s.size() == 5)
            continue;

        for (char c = s[s.size() - 1] + 1; c <= 'z'; c++)
            Q.push(s + c);
    }
}

int main()
{
    #ifdef __DEBUG
        FILE_IN("__UVA_417_input.txt");
        FILE_OUT("__UVA_417_output.txt");
    #endif
    
    FAST_IO;
    
    unordered_map<string, int> strings;
    
    generateAll(strings);
    // generateAllBFS(strings);
    
    string str;
    while(cin>>str)
        cout<<strings[str]<<"\n";
    
    return 0;
}