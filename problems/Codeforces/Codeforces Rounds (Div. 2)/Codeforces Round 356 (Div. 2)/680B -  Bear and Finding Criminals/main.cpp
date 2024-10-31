#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cities,LimakLives,counter=0;
    cin>>cities>>LimakLives;
    vector<bool>criminals(cities);
    for(int i=0;i<cities;i++)
    {
        int enter;
        cin>>enter;
        criminals[i]=enter;
    }
    if(criminals[LimakLives-1])
        counter++;
    int leftCity=LimakLives-2,rightCity=LimakLives;
    while(leftCity>=0 && rightCity<cities)
    {
        if(criminals[leftCity] && criminals[rightCity])
            counter+=2;
        leftCity--; rightCity++;
    }
    while(leftCity>=0)
       if(criminals[leftCity--])
            counter++;
    while(rightCity<cities)
       if(criminals[rightCity++])
            counter++;
    cout<<counter<<endl;
    return 0;
}
