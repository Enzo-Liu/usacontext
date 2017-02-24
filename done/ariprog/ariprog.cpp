/*
ID: liu.enz1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX 150000

int n,m;
int solutions = 0;
int hasBisQuare[MAX] = {0};

ofstream fout ("ariprog.out");
ifstream fin ("ariprog.in");

void prepareBisQuare()
{
  for(int i=0;i<=m;i++)
    for(int j=i;j<=m;j++){
      hasBisQuare[i*i+j*j] = 1;
    }
}

void fit(int a,int b)
{
  for(int i=0;i<n;i++){
    if(hasBisQuare[a+i*b]!=1)
      return;
  }

  solutions++;
  fout<<a<<" "<<b<<endl;
}

void getSolutions()
{
  int biggest = m*m*2;
  int maxb = biggest/(n-1);
  for(int j=1;j<=maxb;j++){
    int maxa = biggest-(n-1)*j;
    for(int i=0;i<=maxa;i++)
      if(hasBisQuare[i]==1)
        fit(i,j);
  }
}

int main() {

  fin>>n>>m;

  prepareBisQuare();
  getSolutions();

  if(solutions==0)
    fout<<"NONE"<<endl;

  return 0;
}
