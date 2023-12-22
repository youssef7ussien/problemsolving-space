/**
 * Title: "Spy-string", Codeforces problem. 
 * Date: Tuesday, 10 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;


void print(const map<string, int> &freq, int N) 
{
    for(auto &it : freq)
        if(it.second >= N) { 
            cout<<it.first<<"\n";
            return;
        }

    cout<<-1<<"\n";
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, M;
        cin>>N>>M;
        
        map<string, int> freq;
        vector<string> strings(N);
        for(int i = 0 ; i < N ; i++) {
            string str, temp;
            cin>>str;

            temp = str, freq[str]++;

            for(int j = 0 ; j < M ; j++)
                for(char ch = 'a' ; ch <= 'z' ; ch++) {
                    if(ch == str[j])
                        continue;
                    char temp = str[j];
                    str[j] = ch, freq[str]++, str[j] = temp;
                }
        }
        
        print(freq, N);
    }
    
    return 0;
}