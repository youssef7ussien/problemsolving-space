/**
 * Title: "Image Preview", Codeforces problem. 
 * Date: Friday, 12 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;

int main()
{
    FAST_IO;
    
    int N, a, b, T;
    string str;
    cin>>N>>a>>b>>T>>str;
    
    VI prefix(N);
    for(int i = 0 ; i < N ; i++)
        prefix[i] = (str[i] == 'w' ? b + 1 : 1) + (i == 0 ? 0 : prefix[i - 1]);

    auto check = [&](const int num) {
        for(int i = 0 ; i <= num ; i++)
            if(prefix[i] + (prefix[N - 1] - prefix[N - 1 - num + i]) + a * num + min(i, num - i) * a <= T)
                return true;

        return false;
    };

    int left = 0, right = N;
    while(left < right) {
        int middle = left + (right - left + 1) / 2;
        check(middle - 1) ? left = middle : right = middle - 1;
    }
    
    cout<<left<<"\n";
    return 0;
}