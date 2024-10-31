/**
 * Title: "Distinct Numbers", CSES problem. 
 * Date: Wednesday, 09 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO         ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    int N;
    cin>>N;

    set<int> numbers;
    for(int i = 0 ; i < N ; i++) {
        int temp; cin>>temp;
        numbers.insert(temp);
    }

    cout<<numbers.size()<<"\n";
    return 0;
}