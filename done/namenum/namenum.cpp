/*
ID: liu.enz1
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

char map[][4]= {{},{},{'A','B','C'},{'D','E','F'},{'G','H','I'},
                      {'J','K','L'},{'M','N','O'},{'P','R','S'},
                      {'T','U','V'},{'W','X','Y'},{}};
char res[5000][13];
int resultNum = 0;

void
getResult(char* num, char data[][13],int start, int end,int offset)
{
  if(num[offset] == 0)
  {
    for(int i=start;i<=end;i++)
      if((int)strlen(data[i])==offset)
      {
        strcpy(res[resultNum++],data[i]);
      }
    return;
  }

  char* mapc = map[num[offset]-'0'];
  int mapcLen = strlen(mapc);
  for(int i = 0;i<mapcLen;i++)
  {
    int low = start,high = end;
    while(low<=high)
    {
      int mid = (low+high+1)/2;
      if(data[mid][offset] < mapc[i]||(int)strlen(data[mid])<=offset) low = mid+1;
      else if(data[mid][offset] == mapc[i] && (mid==start ||(int)strlen(data[mid-1])<=offset || data[mid-1][offset]<mapc[i])){ low = mid; break;}
      else high = mid-1;
    }

    if(low>high)continue;
    high = low;
    for(int j = low;j<=end;j++)
    {
      if(strncmp(data[low],data[j],offset+1)==0)
        high = j;
      else break;
    }
    getResult(num,data,low,high,offset+1);
  }
}

int
main(void)
{
  ofstream fout ("namenum.out");
  ifstream fin ("namenum.in");
  ifstream fin_dict ("dict.txt");
  int len = 4617;
  char data[len][13];
  int i=0;
  string line;
  while(getline(fin_dict,line))
  {
    strcpy(data[i],line.c_str());
    i++;
  }

  fin>>line;
  char num[13];
  memset(num,0,13);
  strcpy(num,line.c_str());
  getResult(num,data,0,len-1,0);
  for(int i=0;i<resultNum;i++)
    fout<<res[i]<<endl;
  if(resultNum==0)
    fout<<"NONE"<<endl;

  return 0;
}

