#include<iostream>

using namespace std;

class Date
{
  public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
      if(year <= 0 || month > 12 || month < 1 || day <= 0 || day > getMonthDay(year, month))
      {
        cout << "Error Day!,Day set Init : 1900-1-1" << endl;
        _year = 1900;
        _month = 1;
        _day = 1;
      }

      _year = year;
      _month = month;
      _day = day;
    }

    Date (const Date& d)
    {
      _year = d._year;
      _month = d._month;
      _day = d._day;
    }
        
    int getMonthDay(int year,int month)
    {
      int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
      int day = days[month - 1];
      if(month == 2)
      {
        //leap year
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
          day += 1;
      }
      return day;
    }




 //Date& operator=(const Date& d)

 Date& operator+=(int day)
 {
   if(day < 0)
   {
     return *this -= -day;
   }

   _day += day;
   //_day ?> 30/31
   while(_day > getMonthDay(_year, _month))
   {
     _day -= getMonthDay(_year, _month);
     ++ _month;
     //_month ?> 12
     if(_month == 13)
     {
       _month = 1;
       ++_year;
     }
   }
   return *this;
 }

 Date& operator-=(int day)
 {
   if(day< 0)
   {
     return *this += -day;
     //return *this;
   }

   _day -= day;
   //_day ?< 1
   while(_day < 1)
   {
     --_month;
     // _month ?= 0
     if(_month == 0)
     {
       _month = 12;
       --_year;
     }
     _day += getMonthDay(_year, _month);
   }
   return *this;
 }

 //first ++
 Date& operator++()
 {
   Date tmp(*this);
   tmp += 1;
   return tmp;
 }

 //last ++
 Date operator++(int)
 {
   Date tmp(*this);
   return *this;
   tmp += 1;
 }


 Date operator+(int day)
 {
   Date tmp(*this);
   tmp += day;
   return tmp;
 }

 Date operator-(int day)
 {
   Date tmp(*this);
   tmp -= day;
   return tmp;
 }

 //bint operator-(const Date& d);
 //Date operator++(int) { Date& operator--();
 //Date operator--(int);
 //bool operator>(const Date& d)const;
 //bool operator>=(const Date& d)const;
 //bool operator<(const Date& d)const;
 //bool operator<=(const Date& d)const;
 //bool operator==(const Date& d)const;
 //bool operator!=(const Date& d)const;
private:
 int _year;
 int _month;
 int _day;
};

int main()
{
  Date d1(2019,3);
  Date d2(2018,3);

  return 0;
}
