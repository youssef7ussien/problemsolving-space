/**
 * Title: "Mirrored String I", Codeforces problem. 
 * Date: Monday, 22 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

bool check(string str)
{
    vector<bool> flags = {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0};

    for(auto it : str)
        if(!flags[it - 'A'])
            return false;

    return true;
}

int main()
{
    FAST_IO;

    TEST_CASES(T) {
        string str;
        cin>>str;

        cout<<(check(str) && str == string(R_ALL(str)) ? "yes" : "no")<<"\n";
    }

    return 0;
}
