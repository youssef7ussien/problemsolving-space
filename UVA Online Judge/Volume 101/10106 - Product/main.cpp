#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> bigInt;

void printBigInt(bigInt bigNum)
{
    for(int i=bigNum.size()-1 ; i>=0 ; i--)
        cout<<bigNum[i];
    cout<<endl;
}

bigInt multiplyTwoBigInt(string strNum1,string strNum2)
{
    if(strNum1=="0" || strNum2=="0")
        return bigInt(1);

    bigInt result(strNum2.length()+strNum1.length()-1);
    reverse(strNum1.begin(), strNum1.end());
    reverse(strNum2.begin(), strNum2.end());

    for(int i=0 ; i<strNum2.length() ; i++)
        for(int j=0 ; j<strNum1.length() ; j++)
        {
            result[i+j]+=(strNum1[j]-'0')*(strNum2[i]-'0');
            if(result[i+j]>9)
            {
                if(i+j+1>=result.size())
                    result.push_back(0);
                result[i+j+1]+=result[i+j]/10;
                result[i+j]%=10;
            }
        }

    return result;
}

int main()
{
	string strNum1,strNum2;

	while(cin>>strNum1>>strNum2)
		printBigInt(multiplyTwoBigInt(strNum1,strNum2));

	return 0;
}
