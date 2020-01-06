#include <iostream>

using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;
public:
    Date(int m, int d, int y)
    {
        month=m;
        day=d;
        year=y;
    }
    void printDate()
    {
        cout<<month<<" "<<day<<" "<<year<<endl;
    }
    void setMonth(int m)
    {
        if(m>0 && m<13)
        {
            month=m;
        }else{
            cout<<"Month out of range"<<endl;
        }
    }
    void setYear(int y)
    {
        if(y>0 && y<2019)
        {
            year=y;
        }else{
            cout<<"Year out of range"<<endl;
        }
    }
    void setDay(int d)
    {
        if(d>0 && d<30)
        {
            day=d;
        }else{
            cout<<"Day out of range"<<endl;
        }
    }
};

int main()
{
    //Date d(31, 8, 2018);
    Date d(31, 8, 2018);
    //error, month is private to Date
    //cout<<d.month;
    //also generates an error for the same reason, month is private
    //d.month=5;
    d.setMonth(13);
    d.setDay(-5);
    d.setYear(2025);
    d.setDay(15);
    d.setYear(2015);
    d.setMonth(12);
    d.printDate();
    return 0;
}
