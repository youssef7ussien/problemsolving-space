#include <iostream>
#include <set>

using namespace std;

int main()
{
    string str;  cin>>str;

    multiset<char>numbers;
    int length=str.size();
    auto it=numbers.begin();

    for(int i=0 ; i<length ; i+=2)
        it=numbers.emplace_hint(it,str[i]);

    it=--numbers.end();
    for(auto i=numbers.begin() ; i!=numbers.end() ; i++)
        i==it? cout<<*i : cout<<*i<<"+";

    return 0;
}
