#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<char>letters;
    char mark;  cin>>mark;
    auto it=letters.begin();
    while(mark!='}')
    {
        char x;
        cin>>x;    if(x=='}') break;
        cin>>mark;
        it=letters.emplace_hint(it,x);
    }
    cout<<letters.size()<<endl;
    return 0;
}
