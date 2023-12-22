#include <iostream>
using namespace std;
int main()
{
    int numArray; cin>>numArray;
    int *resultArray=new int[numArray];
    for(int i=0;i<numArray;i++)
    {
        int Size; cin>>Size;
        int *arr=new int[Size],counter=0;
        bool tooChaotic=false,swaped=false;
        for(int j=0;j<Size;j++)
            cin>>arr[j];
        for(int j=0;j<Size-1;j++)
            if(arr[j]-(j+1)>2)
                { tooChaotic=true; break; }
        if(!tooChaotic)
        {
            for(int k=0;k<Size;k++)
            {
                for(int j=0;j<Size-k-1;j++)
                    if(arr[j]>arr[j+1])
                        {
                            int cpy=arr[j];  arr[j]=arr[j+1]; arr[j+1]=cpy;
                             counter++; swaped=true;
                        }
                if(swaped) swaped=false;
                else    break;
            }
        }
        resultArray[i]=counter;
        delete[] arr;
    }
    for(int i=0;i<numArray;i++)
    {
        if(resultArray[i]==0)   cout<<"Too chaotic"<<endl;
        else cout<<resultArray[i]<<endl;
    }
    delete[] resultArray;
    return 0;
}
