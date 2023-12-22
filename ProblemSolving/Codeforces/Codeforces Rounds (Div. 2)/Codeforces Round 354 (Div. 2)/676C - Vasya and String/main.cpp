#include <bits/stdc++.h>

using namespace std;
#define ALL(v)                      ((v).begin()), ((v).end())
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define SIZE(v)                     ((int)((v).size()))
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;


int countMaxLength(const string &str, const int &K, const char &C)
{
    int left = 0, right = 0, counter = 0, maxLength = 0;
    while (right < SIZE(str))
    {
        counter += (str[right++] != C);

        while (counter > K)
            counter -= (str[left] != C), left++;

        maxLength = max(maxLength, right - left);
    }

    return maxLength;
}

int main()
{
    FAST_IO;

    int K; // N not use in this code
    string str;
    cin>>K>>K>>str;

    cout<<max(countMaxLength(str, K, 'a'), countMaxLength(str, K, 'b'))<<"\n";
    return 0;
}
