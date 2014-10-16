/*
ID: liu.enz1 
PROG: gift1 
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getIndex(string* people,int len,string name)
{
  for(int i=0;i<len;i++)
  {
    if(people[i].compare(name)==0)
      return i;
  }
  return -1;
}

int main() {
  ofstream fout ("gift1.out");
  ifstream fin ("gift1.in");
  int num = 0;
  fin>>num;
  string* people = new string[num];
  for(int i=0;i<num;i++)
  {
    fin>>people[i];
  }
  int* amounts = new int[num];
  for(int i=0;i<num;i++)
  {
    string giver;
    fin>>giver;
    int gnum = getIndex(people,num,giver);
    int money,fnum;
    fin>>money>>fnum;
    if(fnum<=0){
      continue;
    }
    int given = money/fnum;
    string receiver;
    for(int j=0;j<fnum;j++)
    {
      fin>>receiver;
      int index = getIndex(people,num,receiver);
      if(index<0)continue;
      amounts[index]+=given;
    }
    amounts[gnum]-=given*fnum;
  }
  for(int i=0;i<num;i++)
  {
    fout<<people[i]<<" "<<amounts[i]<<endl;
  }
  delete[] people;
  delete[] amounts;
}

