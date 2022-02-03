#include <iostream>

using namespace std;

int main()
{
    int num,minNum=0,maxNum=0,counter[2]={0,0};
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int newNum;
        cin>>newNum;
        if(i!=0)
        {
            if(newNum>maxNum)
            { maxNum=newNum; counter[0]++;  }
            else if(newNum<minNum)
            { minNum=newNum; counter[1]++; }
        }
        else
            minNum=maxNum=newNum;
    }
    cout<<counter[0]<<" "<<counter[1]<<endl;
    return 0;
}
