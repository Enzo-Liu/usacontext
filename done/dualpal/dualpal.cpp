/*
ID: liu.enz1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

#define LEN 40

char
getChar(int n)
{
  if(n<=9)
    return n+'0';
  else
    return n-10+'A';
}


void show(char (&num)[LEN],int n,int base)
{
   int index = 0;
   memset(num,0,LEN);
   int size = log(n)/log(base);
   while(size>=0)
   {
     int cb = pow(base,size);
     int cn =  n/cb;
     n -= cn * cb;
     size --;
     num[index++] = getChar(cn);
   }
}

bool isPal(char* str, int start,int end)
{
  if(start>=end) return true;

  if(str[start]!=str[end])
    return false;

  return isPal(str,start+1,end-1);
}

int
main(void)
{
  ofstream fout ("dualpal.out");
  ifstream fin ("dualpal.in");

  int n,s;
  fin>>n>>s;

  int i = 0;
  long cur = s+1;
  char res[LEN];
  int palN = 0;
  while(i<n)
  {
    for(int b = 2;b<=10;b++)
    {
      memset(res,0,LEN);
      show(res,cur,b);
      if(isPal(res,0,strlen(res)-1))
          palN++;

      if(palN==2) break;
    }

    if(palN >=2) {
      i++;
      fout<<cur<<endl;
    }
    cur+=1;
    palN = 0;
  }

  return 0;
}

