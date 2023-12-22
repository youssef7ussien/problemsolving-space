/**
 * Title: "Three Parts of the Array", Codeforces problem. 
 * Date: Tuesday, 08 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e16+5

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;
typedef vector<Long>                VL;


bool binarySearch(const VL &numbers, Long N, int start)
{
    int left = start, right = SIZE(numbers) - 1;
    while(left <= right) {
        int middle = left + (right - left) / 2;

        if(numbers[middle] == N)
            return true;

        numbers[middle] > N ? left = middle + 1 : right = middle - 1;
    }

    return false;
}

Long solve_2(const VI &numbers) // with binary search O(nlogn)
{
    VL prefix(SIZE(numbers)), suffix(SIZE(numbers));
    
    for(int i = 0 ; i <= SIZE(numbers) ; i++)
        prefix[i] = (i != 0 ? prefix[i - 1] : 0) + numbers[i];
    
    for(int i = SIZE(numbers) - 1 ; i >= 0  ; i--)
        suffix[i] = ( i != SIZE(numbers) - 1 ? suffix[i + 1] : 0) + numbers[i];

    Long maxSum = -INF;
    for(int i = 0 ; i < SIZE(prefix) - 1 ; i++)
        if(binarySearch(suffix, prefix[i], i + 1))
            maxSum = max(maxSum, prefix[i]);
    
    return maxSum == -INF ? 0 : maxSum;
}


Long solve(const VI &numbers) // with two pointer O(n)
{
    Long prefix = numbers[0], suffix = numbers[SIZE(numbers) - 1], maxSum = 0;
    int left = 0, right = SIZE(numbers) - 1;

    while(left < right) {
        if(prefix < suffix)
            prefix += numbers[++left];
        if(prefix > suffix)
            suffix += numbers[--right];
        else
            maxSum = prefix, prefix += numbers[++left];
    }
    
    return maxSum;
}

int main()
{
    FAST_IO;
    
    int N;
    cin>>N;

    VI numbers(N);
    for(auto &it : numbers)
        cin>>it;

    cout<<solve(numbers)<<"\n";
    return 0;
}