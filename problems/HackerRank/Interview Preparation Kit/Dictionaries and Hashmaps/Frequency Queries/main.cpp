#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> frequencyQuery(const vector<vector<int>> &queries)
{
    unordered_map<int,int> hashMap, numberCounted;
    vector<int> isFrequency;

    for(int i=0 ; i<queries.size() ; i++)
    {
        if(queries[i][0]==1)
        {
            if(hashMap[queries[i][1]]>0)
                numberCounted[hashMap[queries[i][1]]]--;
            hashMap[queries[i][1]]++;
            numberCounted[hashMap[queries[i][1]]]++;
        }
        else if(queries[i][0]==2 && hashMap[queries[i][1]]!=0)
        {
            if(numberCounted[hashMap[queries[i][1]]]!=0)
                numberCounted[hashMap[queries[i][1]]]--;
            hashMap[queries[i][1]]--;
            numberCounted[hashMap[queries[i][1]]]++;
        }
        else if(queries[i][0]==3)
           numberCounted[queries[i][1]]>0 ? isFrequency.push_back(1) : isFrequency.push_back(0);
    }

    return isFrequency;
}

int main()
{
    int numQueries;
    cin>>numQueries;
    vector<vector<int>> queries(numQueries);

    for(int i=0 ; i<numQueries ; i++)
    {
        queries[i].resize(2);
        cin>>queries[i][0]>>queries[i][1];
    }

    vector<int> isFrequency=frequencyQuery(queries);
    for(int i=0 ; i<isFrequency.size() ; i++)
        cout<<isFrequency[i]<<endl;

    return 0;
}

