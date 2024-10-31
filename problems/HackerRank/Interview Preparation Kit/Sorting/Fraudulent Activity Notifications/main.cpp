#include <iostream>
#include <vector>

using namespace std;

double median(vector<int> F,int D)
{
    int p=0;
    for(int i = 0; i < 201; i++)
    {
        p+=F[i];
        if(p*2>D)
            return i;

        else if(p*2==D)
        {
            for(int j=i+1 ; ; j++)
                if (F[j])
                    return (i+j)/2.0;
        }
    }
    return -1;
}

int countNotices(const vector<int> &expenditure,int days)
{
    int count=0;
    vector<int> freq(201,0);

    for(int i = 0 ; i<days ; i++)
        freq[expenditure[i]]++;

    for(auto it=expenditure.begin()+days ; it!=expenditure.end() ; it++)
    {
        if(*it>=2.0*median(freq,days))
            count++;
        freq[*(it-days)]--;
        freq[*it]++;
    }

    return count;
}

int main()
{
    int N,days;
   cin>>N>>days;
    vector<int> expenditure(N);
   for(int i=0 ; i<N ; i++)
       cin>>expenditure[i];

    cout<<countNotices(expenditure,days)<<endl;
    return 0;
}
