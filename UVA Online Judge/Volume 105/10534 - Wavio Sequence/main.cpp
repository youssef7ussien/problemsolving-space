// hint: https://www.geeksforgeeks.org/c-program-for-longest-increasing-subsequence/
#include <iostream>
#include <vector>
using namespace std;

#define SIZE(v) ((int)v.size())


void computeLongestSequence1(vector<int> &lengths,const vector<int> &sequence)
{
    int indexCount=1;
    vector<int> temp;
    temp.push_back(sequence[0]);
    for (int i=0 ; i<SIZE(sequence) ; i++)
    {
        if (sequence[i]>temp.back())
        {
            temp.push_back(sequence[i]);
            lengths[i]=++indexCount;
        }
        else
        {
            int index=lower_bound(temp.begin(),temp.end(),sequence[i])-temp.begin();
            temp[index]=sequence[i];
            lengths[i]=index+1;
        }
    }
}

void computeLongestSequence(vector<int> &lengths,const vector<int> &sequence)
{
    vector<int> temp;

    for (int i=0 ; i<SIZE(sequence) ; i++)
    {
        int index=lower_bound(temp.begin(),temp.end(),sequence[i])-temp.begin();
        if(index==SIZE(temp)) temp.push_back(sequence[i]);
        else temp[index]=sequence[i];
        lengths[i]=index+1;
    }
}

int WavioSequenceLength(const vector<int> &sequence)
{
    vector<int> lengthsLIS(SIZE(sequence)), lengthsLDS(SIZE(sequence));

    computeLongestSequence(lengthsLIS,sequence);
    computeLongestSequence(lengthsLDS,vector<int>(sequence.rbegin(),sequence.rend()));
    // sequence  should be reverse and reverse lengthsLDS after compute,
    // can use (i-SIZE(sequence)-1) in for instead of that.

    int maxLength=0;
    for(int i=0 ; i<SIZE(sequence) ; i++)
        maxLength=max(maxLength, 2*min(lengthsLIS[i],lengthsLDS[SIZE(sequence)-i-1])-1);

    return maxLength;
}

int main()
{
    int N;
    while(cin>>N && N!=0)
    {
        vector<int> sequence(N);
        for(auto &it : sequence)
            cin>>it;

        cout<<WavioSequenceLength(sequence)<<endl;
    }

    return 0;
}
