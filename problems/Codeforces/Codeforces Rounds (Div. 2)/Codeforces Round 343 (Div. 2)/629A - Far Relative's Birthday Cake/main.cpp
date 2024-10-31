#include <iostream>
#include <vector>
using namespace std;

#define combinations_2(num) (num*(num-1)/2)

int main()
{
    int n;
    cin>>n;
    vector<int> columnFreq(n,0), rowFreq(n,0);
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
        {
            char input;
            cin>>input;
            if(input=='C')
            {
                rowFreq[i]++;
                columnFreq[j]++;
            }
        }

    int count=0;
    for(int i=0 ; i<n ; i++)
        count+=combinations_2(columnFreq[i])+combinations_2(rowFreq[i]);

    cout<<count<<endl;
    return 0;
}
