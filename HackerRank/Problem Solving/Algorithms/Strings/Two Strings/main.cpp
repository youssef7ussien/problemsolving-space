#include <iostream>

using namespace std;

int main()
{
    int num;
    cin>>num;
    string str1,str2;
    for(int i=0;i<num;i++)
    {
        cin>>str1>>str2;
        int countChar1[26]={0},countChar2[26]={0};
        for(int j=0;j<str1.size();j++)
            countChar1[str1[j]-'a']++;
        for(int j=0;j<str2.size();j++)
            countChar2[str2[j]-'a']++;
        bool finded=false;
        for(int j=0;j<26;j++)
        {
            if(countChar1[j]!=0 && countChar2[j]!=0)
                { finded=true; break; }
        }
        finded==true? cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
    return 0;
}
