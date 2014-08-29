/*
  ID: liu.enz1
  PROG: frac1
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

ofstream fout ("frac1.out");
ifstream fin ("frac1.in");

bool
corprime(int a,int b){
  int temp = 0;
  while(b != 0){
    temp = b;
    b = a%b;
    a = temp;
  }
  if(a==1)
    return true;

  return false;
}

typedef struct Frac{
  int a;
  int b;
} Frac;

Frac res[25600];
int num = 0;
int m;

int
compare(const void* a,const void* b){
  double res = ((Frac*)a)->a*1.0/((Frac*)a)->b -
    ((Frac*)b)->a*1.0/((Frac*)b)->b;
  if(res > 0) return 1;
  if(res < 0) return -1;
  return 0;
}

void
output(){
  qsort(res,num,sizeof(Frac),compare);
  for(int i = 0;i<num; i++)
    fout<<res[i].a<<"/"<<res[i].b<<endl;
}

void
solve(){
  for(int i = 0;i<=m;i++)
    for(int j=i;j<=m;j++)
      if(corprime(i,j)){
        res[num].a = i;
        res[num].b = j;
        num++;
      }
}

int main() {
  fin>>m;
  solve();
  output();
  return 0;
}
