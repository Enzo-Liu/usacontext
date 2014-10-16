/*
ID: liu.enz1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

#define LEN 20

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

void
getSquare(char (&square)[LEN],int n,int base)
{
   int s = n * n;
   show(square,s,base);
}

bool isPal(char* str, int start,int end)
{
  if(start>=end) return true;

  if(str[start]!=str[end])
    return false;

  return isPal(str,start+1,end-1);
}

bool
isPalsquare(char (&square)[LEN])
{
  return isPal(square,0,strlen(square)-1);
}

int
main(void)
{
  ofstream fout ("palsquare.out");
  ifstream fin ("palsquare.in");

  int base;
  fin>>base;

  char square[LEN];
  char num[LEN];
  for(int i=1;i<=300;i++)
  {
    getSquare(square,i,base);
    show(num,i,base);
    if(isPalsquare(square))
      fout<<num<<" "<<square<<endl;
  }

  return 0;
}

