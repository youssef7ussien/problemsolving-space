#include <iostream>
using namespace std;

int inputText()
{
    int counter=0;
    string text;
    cin>>text;
    for(int i=0 ; i<(int)text.size()-1 ; i++)
    {
        if(text[i]==text[i+1])
            counter++;
    }
    return counter;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0 ; i<n ; i++)
        cout<<inputText()<<endl;
    return 0;
}
