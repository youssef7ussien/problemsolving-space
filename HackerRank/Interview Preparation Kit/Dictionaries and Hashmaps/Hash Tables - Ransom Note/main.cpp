#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int m , n , indxMagazine=0 , indxNote=0;
    cin>>m>>n;
    vector<string>magazine(m),note(n);
    string word;
    for(int i=0;i<m;i++)
        cin>>magazine[i];
    for(int i=0;i<n;i++)
        cin>>note[i];
    sort(magazine.begin(),magazine.end());
    sort(note.begin(),note.end());
    while(indxMagazine!=m && indxNote!=n)
    {
        if(magazine[indxMagazine++]==note[indxNote])
            indxNote++;
    }
    if(indxNote==n)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
