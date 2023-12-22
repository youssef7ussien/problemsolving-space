#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int lenght,index=0;
    cin>>lenght;
    vector<char>encryptedWord(lenght);
    string unencryptedWord="";
    for(int i=0;i<lenght;i++)
        cin>>encryptedWord[i];
    while(lenght--)
    {
        if(lenght%2==0)
            unencryptedWord=unencryptedWord+encryptedWord[index++];
        else
            unencryptedWord=encryptedWord[index++]+unencryptedWord;
    }
    cout<<unencryptedWord;
    return 0;
}
