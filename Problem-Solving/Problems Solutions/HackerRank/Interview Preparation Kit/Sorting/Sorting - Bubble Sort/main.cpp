#include <iostream>
#include <vector>

using namespace std;

void swapNum(int *num1,int *num2)
{
    int temp=*num1;
    *num1=*num2;
    *num2=temp;
}

int main()
{
    int length,countSwap=0;
    cin>>length;

    vector<int> arr(length);
    for(int i=0 ; i<length ; i++)
        cin>>arr[i];

    for(int i=0 ; i<arr.size()-1 ; i++)
    {
        bool swapped=false;
        for(int j=0 ; j<arr.size()-i-1 ; j++)
            if(arr[j] > arr[j+1])
            {
                swapNum(&arr[j],&arr[j+1]);
                swapped=true;
                countSwap++;
            }
        if(!swapped)
            break;
    }

    cout<<"Array is sorted in "<<countSwap<<" swaps."<<endl;
    cout<<"First Element: "<<arr[0]<<endl;
    cout<<"Last Element: "<<arr[arr.size()-1]<<endl;

    return 0;
}
