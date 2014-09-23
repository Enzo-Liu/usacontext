/*
  ID: liu.enz1
  PROG: inflate
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <set>
#include <stdlib.h>
#include <math.h>

using namespace std;

ofstream fout ("inflate.out");
ifstream fin ("inflate.in");

#define MAX 10000

int m,n;

typedef struct{
  int minite,point;
}Problem;

double
value(Problem& problem){
  return problem.point*1.0/problem.minite;
}

int compare(const void*a,const void*b){
  double diff = value(*(Problem*)a)-value(*(Problem*)b);
  if(diff<0) return -1;
  else if (diff > 0) return 1;
  return 0;
}

int most = 0;
Problem problems[MAX];

void
input(){
  fin>>m>>n;
  for(int i=0;i<n;i++)
    fin>>problems[i].point>>problems[i].minite;
  qsort(problems,n,sizeof(Problem),compare);
}

void
output(){
  fout<<most<<endl;
}
int f[MAX] = {0};

void
solve(){
  for(int i=1;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(j>=problems[i-1].minite)
        f[j] = max(f[j],f[j-problems[i-1].minite]+problems[i-1].point);
    }
  }
  most = f[m];
}

int main() {
  input();
  solve();
  output();
  return 0;
}
