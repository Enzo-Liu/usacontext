/*
ID: liu.enz1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int equal(char a ,char b)
{
  return a==b||a=='w'||b=='w';
}

int max (int * res, int len)
{
  if (len ==1)
    return res[0];
  int max=0,last = res[0];
    cout<<res[0]<<" ";
  for(int i=1;i<len;i++)
  {
    cout<<res[i]<<" ";
    if(res[i-1]<0)
      last = res[i]-res[i-1];
    else
    {
      int tmp = last+(res[i]<0?res[i+1]:res[i]);
      last = res[i];
      max = max>tmp?max:tmp;
    }
  }
  return max;
}


int beads(int num,const char* necklace)
{
  int count=0;
  char last = necklace[0],begin=necklace[0],end=necklace[0];
  int index = 0,wnum = 0;
  int* res = new int[num+1];
  for(int i = 0;i<num;i++)
  {
    if(equal(last,necklace[i]))
    {
      count++;
      if(last =='w' && necklace[i]!='w') last = necklace[i];
      if(begin == 'w'&& necklace[i]!='w') begin = necklace[i];
      if(necklace[i]=='w') wnum++;else wnum = 0;
    }
    else
    {
      res[index++]= count;
      if(wnum != 0) res[index++]= -wnum;
      last = necklace[i];
      if(last =='r'||last == 'b') end = last;
      count = 1;
      wnum = 0;
    }
  }
  if(equal(last,necklace[num-1])) res[index++]=count;
  if(index >=2){
  if(begin == end) {res[0]=res[index-1]+res[0]+(res[index-2]<0?-res[index-2]:0);res[index-1]=res[0]+(res[index-2]<0?res[index-2]:0);}
  else res[0]+=wnum;}
  return max(res, index);
}

int max(int a ,int b)
{
  if (a >b) return a;
  return b;
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int a;
    string b;
    fin >> a >> b;
    fout <<beads(a,b.c_str()) << endl;
    return 0;
}
