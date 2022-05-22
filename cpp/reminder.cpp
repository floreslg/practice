#include<assert.h>
#include<iostream>


class Date
{
    private:
    int day;
    int month;
    int year;

    public:
    Date(int intDate);
    Date(const int intDay, const int intMonth, const int intYear);

    bool operator== (const Date&);

};


int main()
{
    Date date1(22052023);
    Date date2(22, 05, 2023);

    assert(date1 == date2);
}


Date::Date(int intDate)
{
    // get the left side using /
    day = intDate/1000000;

    // get the right side using % (reminder)
    year = intDate%10000;

    // get the middle
    month = (intDate/10000)%100;

    std::cout << day << "/" << month << "/" << year << std::endl;
}


Date::Date(const int intDay, const int intMonth, const int intYear)
{
    day = intDay;
    month = intMonth;
    year = intYear;
}


bool Date::operator== (const Date& date)
{
    return (day == date.day && 
            month == date.month &&
            year == date.year);
}