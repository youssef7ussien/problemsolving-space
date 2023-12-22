// To understand how to solve a problem: https://www.geeksforgeeks.org/counting-inversions/
#include <iostream>
#include <vector>

using namespace std;
typedef long long Long;
typedef vector<Long> Vector;

Long merge(Vector *arr,int left,int right,int middle)
{
    Vector leftArr(middle-left+1), rightArr(right-middle);

    for(int i=0 ; i<(int)leftArr.size() ; i++)
        leftArr[i]=(*arr)[left+i];
    for(int j=0 ; j<(int)rightArr.size() ; j++)
        rightArr[j]=(*arr)[middle+1+j];

    int i=0, j=0, k=left;
    Long counter=0;

    while(i<(int)leftArr.size() && j<(int)rightArr.size())
    {
        if(leftArr[i]<=rightArr[j])
            (*arr)[k]=leftArr[i], i++;
        else
            (*arr)[k]=rightArr[j], j++, counter+=((int)leftArr.size()-i);
        k++;
    }

    while(i<(int)leftArr.size())
        (*arr)[k++]=leftArr[i++];
    while(j<(int)rightArr.size())
        (*arr)[k++]=rightArr[j++];

    return counter;
}

Long countInversions(Vector *arr,int left,int right)
{
    if(left>=right)
        return 0;
    int middle=left+(right-left)/2;
    return countInversions(arr,left,middle) + countInversions(arr,middle+1,right) + merge(arr,left,right,middle);
}

int main()
{
    int d;
    cin>>d;
    for(int i=0 ; i<d ; i++)
    {
        int n;
        cin>>n;
        Vector arr(n);
        bool isSorted=true;
        for(int j=0 ; j<n ; j++)
        {
            cin>>arr[j];
            if(j>0 && arr[j]<arr[j-1] )
                isSorted=false;
        }
        isSorted ? cout<<"0"<<endl : cout<<countInversions(&arr,0,n-1)<<endl;
    }
    return 0;
}
