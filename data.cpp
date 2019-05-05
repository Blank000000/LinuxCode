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
   }

   _day -= day;
   //_day ?< 1
   while(_day < 1)
   {
     --_month;
     //_month ?= 0
     if(_month == 0)
     {
       _month = 12;
       --_year;
     }
     _day += getMonthDay(_year, _month);
   }
   return *this;
 }

 //++Date
 Date& operator++()
 {
   return *this += 1;
 }

 //Date++
 Date operator++(int)
 {
   Date tmp(*this);
   *this += 1;
   return tmp;
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
 
 //--Date
 Date& operator--()
 {
   return *this -= 1;
 }

 //Date--
 Date operator--(int)
 {
   Date tmp(*this);
   *this -= 1;
   return tmp;
 }


 bool operator>(const Date& d)const
 {
   if(this->_year > d._year)
   {
     return true;
   }
   else if(_year == d._year)
   {
     if(_month > d._month)
     {
       return true;
     }
     else if(_month == d._month)
     {
       if(_day > d._day)
         return true;
     }
   }
   return false;
 }

 bool operator>=(const Date& d)const
 {
   return (*this > d) || (*this == d);
 }


 bool operator<(const Date& d)const
 {
   return !(*this >= d);
 }


 bool operator<=(const Date& d)const
 {
   return (*this < d) || (*this == d);
 }


 bool operator==(const Date& d)const
 {
   _year == d._year && _month == d._month && _day == d._day;
 }
 bool operator!=(const Date& d)const
 {
   return !(*this == d);
 }

 int operator-(const Date& d)
 {
   Date tmp(*this);
   int flag = 1;
   if(tmp < d)
     flag = -1;
   int day;
   if(tmp < d)
   {
     while(tmp < d)
     {
        ++tmp;
        ++day;
     }
   }
   else{
     while(tmp > d)
     {
       --tmp;
       ++day;
     }
   }
 }

 void display()
 {
   cout << _year << "-" << _month << "-"<< _day << endl;

 }


private:
 int _year;
 int _month;
 int _day;
};

void testDate()
{
  Date d1(2019,1,30);
  Date d2(2018,1,30);

  d1++;
  cout << "d1(2019, 1, 30) ++ :" << endl;
  d1.display();
  d2--;
  cout << "d2(2019, 2,28) -- :" << endl;
  d2.display();
  Date d3 = d1 + 62;
  cout << "d1(2019, 1, 30) ++  + 62:" << endl;
  d3.display();
  Date d4 = d2 - 39; 
  cout << "d1(2019, 1, 30) -- - 39:" << endl;
  d4.display();
}

int main()
{
  testDate();

  return 0;
}
