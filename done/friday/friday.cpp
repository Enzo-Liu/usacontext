/*
ID: liu.enz1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getMonthDays(int year, int month)
{
  if(month == 4 || month == 6 || month==9 ||month==11 )
    return 30;
  if(month != 2)
    return 31;

  if((year%4==0 && year%100!=0)||(year%400==0))
  {
    return 29;
  }
  return 28;
}

int getWeekDayByLeapNum(int start,int leapNum)
{
  int n = leapNum%7;
  return (start+n)%7;
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int years = 0;
    fin>>years;
    int startYear = 1900;
    int startWeekdays = 1;
    int frequency[7] = {0};
    for(int i = 0;i<years;i++)
    {
      int year = startYear+i;
      for(int j = 0;j<12;j++)
      {
        int days = getMonthDays(year,j+1);
        frequency[getWeekDayByLeapNum(startWeekdays,12)]+=1;
        startWeekdays = getWeekDayByLeapNum(startWeekdays,days);
      }
    }
    fout<<frequency[6]<<" ";
    for(int i = 0;i<5;i++)
    {
      fout<<frequency[i]<<" ";
    }
    fout<<frequency[5]<<endl;
    return 0;
}

