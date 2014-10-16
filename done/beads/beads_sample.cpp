/*
ID: liu.enz1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAXN 400

string necklace;
int len;

int mod (int n ,int m)
{
  while(n<0)
    n+=m;
  return n%m;
}

int nbreak(int p ,int dir)
{
  char color = 'w';
  int i,n;

  if(dir>0)
    i=p;
  else
    i=mod(p-1,len);

  for(n=0;n<len;n++,i=mod(i+dir,len))
  {
    if(color=='w' && necklace[i]!='w')
      color = necklace[i];
    if(color !='w' && necklace[i]!='w' && necklace[i]!=color)
      break;
  }
  return n;
}

int main(void)
{
  ofstream fout ("beads.out");
  ifstream fin ("beads.in");
  fin >> len >> necklace;

  int i,n,m;

  m=0;
  for(i=0;i<len;i++)
  {
    n = nbreak(i,1)+nbreak(i,-1);
    if(n>m)m=n;
  }

  if(m>len) m=len;
  fout<<m<<endl;
  return 0;
}
