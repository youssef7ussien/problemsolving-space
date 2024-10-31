#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;
    cout<<( N>M ? M : (M % (int)pow(2,N)))<<"\n";
    return 0;
}
