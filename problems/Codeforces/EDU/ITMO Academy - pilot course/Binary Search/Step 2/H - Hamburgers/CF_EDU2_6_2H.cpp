/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Monday, 04 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                   ((int)((v).size()))
#define FAST_IO                  ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long                Long;
typedef unordered_map<char, int> MAP;


struct Item {
    int n, p;
};

bool check(Item B, Item S, Item C, MAP freq, Long R, Long middle)
{
    return (max(0LL, freq['B'] * middle - B.n) * B.p) 
        + (max(0LL, freq['S'] * middle - S.n) * S.p)
        + (max(0LL, freq['C'] * middle - C.n) * C.p) <= R;
}

Long binarySearch(const string &str, Item B, Item S, Item C, Long R)
{
    MAP freq;
    for(auto &it : str)
        freq[it]++;

    Long left = 0, right = 1e13;
    while(left < right) {
        Long middle = left + (right - left + 1) / 2;

        check(B, S, C, freq, R, middle) ? left = middle : right = middle - 1;
    }

    return left;
}

int main()
{
    FAST_IO;
        
    string str;
    Item B, S, C;
    Long R;
    
    cin>>str>>B.n>>S.n>>C.n>>B.p>>S.p>>C.p>>R;
    
    cout<<binarySearch(str, B, S, C, R)<<"\n";
    return 0;
}