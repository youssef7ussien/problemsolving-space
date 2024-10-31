/**
 * Title: "Alphabetic Removals", Codeforces problem. 
 * Date: Tuesday, 01 February 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef pair<char, int>             PCI;


int main()
{  
    FAST_IO;
    
    int N, K;
    string str;
    
    cin>>N>>K>>str;

    vector<PCI> freq(N);

    for(int i=0 ; i<N ; i++)
        freq[i] = {str[i], i};

    sort(ALL(freq));

    sort(freq.begin() + K, freq.end(), [](const PCI &a,const PCI &b){ return a.second < b.second; });

    for(int i=K ; i<N ; i++)
        cout<<freq[i].first;
    cout<<"\n";
    
    return 0;
}