/*
  ID: liu.enz1
  PROG: combo
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

ofstream fout ("combo.out");
ifstream fin ("combo.in");

int n;
int pass[2][3];
int sol = 0;

void
input(){
  fin>>n;
  for(int i=0;i<2;i++)
    for(int j=0;j<3;j++)
      fin>>pass[i][j];
}

void
output(){
  fout<<sol<<endl;
}

bool close(int x,int y){
  return abs(x-y)<=2 || abs(x-y)>=n-2;
}

bool isSol(int a,int b,int c){
  for(int i=0;i<2;i++)
    if(close(a,pass[i][0])
       && close(b,pass[i][1])
       && close(c,pass[i][2]))
      return true;
  return false;
}

void
solve(){
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      for(int k=1;k<=n;k++)
        if(isSol(i,j,k))
          sol++;
}

int main() {
  input();
  solve();
  output();
  return 0;
}
