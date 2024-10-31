#include <bits/stdc++.h>

using namespace std;
#define SIZE(V) ((int)V.size())

int binarySearch(const vector<int> &books,const int &M,const int &index)
{
    int left=0, right=SIZE(books)-1;
    while(left<=right)
    {
        int middle=(left+right)/2;
        if(books[index]+books[middle]==M && index!=middle)
            return books[middle];
        else if(books[index]+books[middle]<=M)
            left=middle+1;
        else
            right=middle-1;
    }
    return -1;
}

void findBooks(vector<int> books,const int &M)
{
    sort(books.begin(),books.end());

    pair<int,int> book={-1,-1};
    for(int i=0 ; i<SIZE(books) ; i++)
    {
        pair<int,int> tempBook={books[i],binarySearch(books,M,i)};

        if((book.second==-1 && tempBook.second!=-1)
            || (abs(tempBook.first-tempBook.second)<abs(book.first-book.second)))
            book=tempBook;
    }

    book.first>book.second ?
    cout<<"Peter should buy books whose prices are "<<book.second<<" and "<<book.first<<".\n\n"
    : cout<<"Peter should buy books whose prices are "<<book.first<<" and "<<book.second<<".\n\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N,M;
    while(cin>>N)
    {
        vector<int> books(N);
        for(auto &it : books)
            cin>>it;
        cin>>M;

        findBooks(books,M);
    }

    return 0;
}
