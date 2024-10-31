#include <bits/stdc++.h>

using namespace std;
#define SIZE(s) ((int)s.size())

bool isFoundPalindrome(const vector<int> &sequence)
{
    for(int i=0 ; i<SIZE(sequence) ; i++)
        for(int j=i+2 ; j<SIZE(sequence) ; j++)
            if(sequence[i]==sequence[j])
                return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin>>T;

    while(T--)
    {
        int N;
        cin>>N;
        vector<int> sequence(N);

        for(auto &it : sequence)
            cin>>it;

        cout<<(isFoundPalindrome(sequence) ? "YES" : "NO")<<"\n";
    }
    return 0;
}
