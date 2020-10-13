#include <iostream>
using namespace std;

struct Date {
    int day=0, mounth=0, year=0, consumption=0;

    bool operator==(const Date& date) const
    {
        return this->day==date.day
            && this->mounth==date.mounth
            && this->year==date.year;
    }

    void operator=(const Date& date)
    {
        this->day=date.day;
        this->mounth=date.mounth;
        this->year=date.year;
        this->consumption=date.consumption;
    }

    bool isLeap()
    {
        return ((year%4==0 && year%100!=0) || year%400==0);
    }
};


bool isDifferenceOneDay(Date prevDate,Date date)
{
    if(--date.day==0)
    {
        int mounth[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if(--date.mounth==0)
            date.year--, date.mounth=12;
        date.day=(date.mounth==2 && date.isLeap()) ? 29 : mounth[date.mounth-1];
    }
    return date==prevDate;
}

int main()
{
    int N;
    while(cin>>N && N!=0)
    {
        Date date, prevDate;
        int sum=0, countDays=0;
        while(N--)
        {
            cin>>date.day>>date.mounth>>date.year>>date.consumption;

            if(isDifferenceOneDay(prevDate,date))
                sum+=abs(prevDate.consumption-date.consumption), countDays++;
            prevDate=date;
        }
        cout<<countDays<<" "<<sum<<endl;
    }

    return 0;
}
