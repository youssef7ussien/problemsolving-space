#include <iostream>
#include <string>
using namespace std;
int main()
{
    char keyboard[30]={'q','w','e','r','t','y','u','i','o','p',
                       'a','s','d','f','g','h','j','k','l',';',
                       'z','x','c','v','b','n','m',',','.','/'} , direction;
    string sentence;
    cin>>direction>>sentence;
    if(direction=='R' || direction=='r')
        for(int i=0;i<sentence.size();i++)
        {
            for(int j=0;j<30;j++)
                if(sentence[i]==keyboard[j])
                    { sentence[i]=keyboard[j-1]; break; }
        }
    else if (direction=='L' || direction=='l')
        for(int i=0;i<sentence.size();i++)
        {
            for(int j=0;j<30;j++)
                if(sentence[i]==keyboard[j])
                    { sentence[i]=keyboard[j+1]; break; }
        }
    cout<<sentence<<endl;

    return 0;
}
