#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

vector<int> readFile(int &n,int &d)
{
    ifstream inFile("input.txt");

    string nd_temp;
    getline(inFile, nd_temp);

    vector<string> nd = split_string(nd_temp);

    n = stoi(nd[0]);

    d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(inFile, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    return expenditure;
}

int main()
{
    int N,days;
//    cin>>N>>days;
    vector<int> expenditure=readFile(N,days);
//    cout<<N<<" "<<days<<endl;
//    for(int i=0 ; i<N ; i++)
//        cout<<expenditure[i]<<" ";
//    for(int i=0 ; i<N ; i++)
//        cin>>expenditure[i];

    cout<<countNotices(expenditure,days)<<endl;
    return 0;
}
