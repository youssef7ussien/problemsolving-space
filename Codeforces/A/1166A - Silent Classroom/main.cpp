#include <iostream>
using namespace std;

#define combinations_2(num) (num*(num-1)/2)

int main()
{
    int n,freq[26]={0};
    cin>>n;

    for(int i=0 ; i<n ; i++)
    {
        string name;
        cin>>name;
        freq[name[0]-'a']++;
    }

    int count=0;
    for(int i=0 ; i<26 ; i++)
        if(freq[i]>2)
            count+=combinations_2(freq[i]/2)+combinations_2((freq[i]-freq[i]/2));

    cout<<count<<endl;
    return 0;
}
