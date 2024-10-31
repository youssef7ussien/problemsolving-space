#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int s1,s2;
    long long queries,comVasya=0,comPetya=0;
    cin>>s1;
    vector<long long>elements(s1);
    for(int i=0;i<s1;i++)
    {
        int enter;
        cin>>enter;
        elements[enter]=i;
    }
    cin>>s2;
    for(int i=0;i<s2;i++)
    {
        cin>>queries;
        comVasya+=elements[queries]+1;
        comPetya+=s1-elements[queries];
    }
    cout<<comVasya<<" "<<comPetya<<endl;
    return 0;
}

