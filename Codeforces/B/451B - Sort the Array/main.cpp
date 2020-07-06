#include <iostream>

using namespace std;

int isArraySorted(int arr[], int s)
{  // If it return -1 this means it's sorted ,else return any number this means it isn't sorted
	for (int i=0 ; i<s-1 ; i++)
	{
		if(arr[i]>arr[i+1])
			return i;
	}
	return -1;
}
void reverseArray(int arr[],int beginSubArray,int endSubArray)
{
	while(beginSubArray<endSubArray)
	{
	    int cpy=arr[beginSubArray];
		arr[beginSubArray++]=arr[endSubArray];
		arr[endSubArray--]=cpy;
	}
}
int main()
{
    int s; cin>>s;
    int *arr=new int[s],beginSubArray=-1,endSubArray=0;
    for(int i=0;i<s;i++)
        cin>>arr[i];
    beginSubArray=isArraySorted(arr,s);
    if(beginSubArray==-1)
    { cout<<"yes\n"<<"1 1"<<endl; return 0; }
    endSubArray=beginSubArray;
    while((endSubArray<s-1) && (arr[endSubArray]>arr[endSubArray+1]))
        endSubArray++;
    reverseArray(arr,beginSubArray,endSubArray);
    if(isArraySorted(arr,s)==-1)
        cout<<"yes"<<endl<<beginSubArray+1<<"  "<<endSubArray+1<<endl;
    else
        cout<<"no"<<endl;
    delete[] arr;
    return 0;
}
