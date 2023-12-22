/**
 * Title: "Card Substrings", Uncategorized problem. 
 * Date: Tuesday, 26 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    int N, M;
    string str, card;
    cin>>N>>M>>str>>card;

    map<char, int> freq;
    for(auto &it : card)
        freq[it]++;

    int left = 0, right = 0;
    Long result = 0;

    while(right < N) {
        if(freq[str[right]] > 0)
            freq[str[right]]--, result += right - left + 1;
        else {
            while(left <= right && freq[str[right]] <= 0)
                freq[str[left++]]++;

            if(freq[str[right]] > 0)
                freq[str[right]]--, result += right - left + 1;
        }
        
        right++;
    }

    cout<<result<<"\n";
    return 0;
}