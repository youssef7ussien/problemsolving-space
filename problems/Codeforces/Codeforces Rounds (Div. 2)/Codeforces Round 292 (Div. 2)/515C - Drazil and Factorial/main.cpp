#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string digits[]={"","","2","3","322","5","53","7","7222","7332"};
    string strNum,result;
    int length;
    cin>>length>>strNum;

    for(int i=0 ; i<length ; i++)
        result+=digits[strNum[i]-'0'];

    sort(result.rbegin(), result.rend());
    cout<<result<<endl;
    return 0;
}
