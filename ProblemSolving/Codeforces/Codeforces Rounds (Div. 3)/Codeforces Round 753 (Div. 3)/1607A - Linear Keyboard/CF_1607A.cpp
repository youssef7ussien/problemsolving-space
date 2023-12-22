#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        string keyboard, word;

        cin>>keyboard>>word;

        int counter=0;
        for(int i=0 ; i<SIZE(word)-1 ; i++)
            counter += abs((int)(keyboard.find(word[i]) - keyboard.find(word[i+1])));

        cout<<counter<<"\n";
    }
    return 0;
}