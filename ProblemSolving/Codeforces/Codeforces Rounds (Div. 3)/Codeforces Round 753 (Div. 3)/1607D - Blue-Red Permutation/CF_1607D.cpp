#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long         Long;
typedef pair<int, int>    PII;
typedef vector<int>       VI;

struct Assist {
    int value;
    char color;
    
    bool operator <(const Assist &item) const {
        return (color < item.color  || (color == item.color && value < item.value));
    }

    bool make(int num) {
        return ((value >= num && color == 'B') || (value <= num && color == 'R'));
    }
};

bool solve(vector<Assist> &items)
{
    sort(ALL(items));

    for(int i=0 ; i<SIZE(items) ; i++)
        if(!items[i].make(i+1))
            return false;

    return true;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        vector<Assist> items(N);
        for(auto &it : items)
            cin>>it.value;

        for(auto &it : items)
            cin>>it.color;
        
        cout<<(solve(items) ? "YES" : "NO")<<"\n";
    }

    return 0;
}