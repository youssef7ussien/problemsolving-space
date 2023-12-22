#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * A solution will be to represent our triplets by ( a_j/r , a_j , a_j*r )
 *  , where r is the common ratio and 0 <= j < n
 *  So, we need to find a_i=a_j/r and a_j*r where j < i < k
 *  We use two maps. Let's call them right and left. Initially, in the right map we
 *  store the frequency of all the elements. Now, as we traverse the
 *  array elements from left side, we first decrement it's count from right
 *  map by 1, then we check the count of a_j*r in the right map and the count of check a_j/r
 *  in the left map. We, increment our answer by right(a_j*r) * left(a_j/r)
 *  At last we increment the count of a_j in the left map by 1.
 *
 *  example :
 *  4 2
 *  1 2 2 4
 *
 *  -------------------
 *  solution :
 *
 *  right map = 0 1 2 0 4
 *  left map  = 0 0 0 0 0
 *  counter = 0
 *
 *  for loop i < 4
 *
 *  when i = 0 , a_i = 1
 *      right = 0 0 2 0 1
 *      check if( a_i % r = 0 && i < size-1 ) -> ( 1%2 = 0 && i=0 < 3 ) -> false
 *               , i < size-1 In order not to create places in the map it will not be used
 *
 *      left  = 0 1 0 0 0
 *
 *  when i = 1 , a_i = 2
 *      right = 0 0 1 0 1
 *      check if( a_i % r = 0 && i < size-1 ) -> ( 2%2 = 0 && i=1 < 3 ) -> true
 *          counter = counter + ( right(2*2) * left(2/2) ) = 0 + ( 1 * 1 ) = 1
 *      left  = 0 1 1 0 0
 *
 *
 *  when i = 2 , a_i = 2
 *      right = 0 0 0 0 1
 *      check if( a_i % r = 0 && i < size-1 ) -> ( 2%2 = 0 && i=2 < 3 ) -> true
 *          counter = counter + ( right(2*2) * left(2/2) ) = 1 + ( 1 * 1 ) = 2
 *      left  = 0 1 2 0 0
 *
 *  when i = 3 , a_i = 4
 *      right = 0 0 0 0 0
 *      check if( a_i % r = 0 && i < size-1 ) -> ( 4%2 = 0 && i=3 < 3 ) -> false
 *
 *      left  = 0 1 2 0 1
 *
 *  In the end, the counter = 2
 */

long long countTriplets(long long arr[],int size,long long commonRatio)
{
    long long counter=0;
    unordered_map<long long, long long> left, right;

    for (int i=0 ; i<size ; i++)
        right[arr[i]]++;

    for (int i=0 ; i<size ; i++)
    {
        right[arr[i]]--;
        if(arr[i]%commonRatio==0 && i<size-1)
            counter+=right[arr[i]*commonRatio]*left[arr[i]/commonRatio];

        left[arr[i]]++;
    }
    return counter;
}

int main()
{
    int size;
    long long commonRatio;
    cin>>size>>commonRatio;

    long long *arr=new long long[size];
    for(int i=0 ; i<size ; i++)
        cin>>arr[i];

    cout<<countTriplets(arr,size,commonRatio)<<endl;

    delete[] arr;
    return 0;
}
