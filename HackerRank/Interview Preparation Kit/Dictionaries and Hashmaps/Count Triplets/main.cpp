#include <iostream>

using namespace std;

int countTriplets(int arr[],int Size,int commonRatio)
{
    int counter=0;
    for(int i=0;i<Size-2;i++)
    {
        int j=i+1,k=i+2;
        while(j>i && k<Size)
        {
            if(arr[j]/arr[i]==commonRatio && arr[j]/arr[i]==arr[k]/arr[j])
            {
                cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<"  |  "<<i<<" "<<j<<" "<<k<<endl;
                counter++;
                k++;
                j++;
            }
            if(arr[j]%arr[i]==0 && arr[k]%arr[j]==0)
            {
                if(arr[j]/arr[i]<arr[k]/arr[j])
                    j--;
                else k++;
            }
            else if (arr[j]%arr[i]==0)
                k++;
            else j--;
        }
    }
    /*for(int j=1;j<Size-1;j++)
    {
        int i=j-1,k=j+1;
        while(i>=0 && k<Size)
        {
            while(arr[j]%arr[i]==0 && arr[k]%arr[j]==0 && arr[j]/arr[i]==arr[k]/arr[j])
            {
                cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<"  |  "<<i<<" "<<j<<" "<<k<<endl;
                counter++;
                k++;
                i--;
            }
            if(arr[j]%arr[i]==0 && arr[k]%arr[j]==0)
            {
                if(arr[j]/arr[i]<arr[k]/arr[j])
                    i--;
                else k++;
            }
            else if (arr[j]%arr[i]==0)
                k++;
            else i--;
        }
    }*/
    return counter;
}
int main()
{
    int Size,commonRatio;
    cin>>Size>>commonRatio;
    int arr[Size];
    for(int i=0;i<Size;i++)
        cin>>arr[i];
    cout<<countTriplets(arr,Size,commonRatio)<<endl;
    return 0;
}



long long subsequences(int a[], int n, int r)
{
    // hashing to maintain left and right array
    // elements to the main count
    unordered_map<int, int> left, right;

    // stores the answer
    long long ans = 0;

    // traverse through the elements
    for (int i = 0; i < n; i++)
        right[a[i]]++; // keep the count in the hash

    // traverse through all elements
    // and find out the number of elements as k1*k2
    for (int i = 0; i < n; i++)
    {

        // keep the count of left and right elements
        // left is a[i]/r and right a[i]*r
        long long c1 = 0, c2 = 0;

        // if the current element is divisible by k,
        // count elements in left hash.
        if (a[i] % r == 0)
            c1 = left[a[i] / r];

        // decrease the count in right hash
        right[a[i]]--;

        // number of right elements
        c2 = right[a[i] * r];

        // calculate the answer
        ans += c1 * c2;

        left[a[i]]++; // left count of a[i]
    }

    // returns answer
    return ans;
}
