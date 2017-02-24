/*
  ID: liu.enz1
  PROG: kimbits
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

#define MAXN 31
#define MAXL 31

ofstream fout ("kimbits.out");
ifstream fin ("kimbits.in");

int n,l;
unsigned long long i;
unsigned long long f[MAXN+1][MAXL+1];
char result[MAXN] = {'0'};

void
input(){
  fin>>n>>l>>i;
}

void
output(){
  for(int j=n;j>0;j--){
    fout<<((result[j]=='1')?'1':'0');
  }
  fout<<endl;
}

unsigned long long chose(int n,int k){
  if (k == 0) return 1;
  else
    return (n*chose(n-1,k-1))/k;
}

//f[0,0] = 1;
void
solve(){
  for(int k=0;k<=n;k++)
    for(int j=0;j<=k&&j<=l;j++){
      if(j==0) f[k][j] =1;
      else
        f[k][j] = f[k][j-1]+chose(k,j);
    }
  int t=l;
  int k = n;
  while(k!=0){
    int tmp1 = t>k?k:t;
    int tmp2 = t>(k-1)?(k-1):t;
    if(f[k][tmp1]>=i && f[k-1][tmp2]<i){
      result[k] = '1';
      i -= f[k-1][tmp2];
      k--;
      t--;
    }else{
      result[k] = '0';
      k--;
    }
  }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
