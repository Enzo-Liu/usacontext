/*
  ID: liu.enz1
  PROG: nocows
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

ofstream fout ("nocows.out");
ifstream fin ("nocows.in");

int n,k;
int solutions = 0;
int cal[200][100] = {{0}};
int calB[200][100] = {{0}};

void
input(){
  fin>>n>>k;
  for(int i=0;i<200;i++)
    for(int j=0;j<100;j++){
      cal[i][j] = -1;
      calB[i][j] = -1;
    }
}

void
output(){
  fout<<solutions<<endl;
}

int
nocows(int n,int k);

void
calBelow(int n,int t,int k){
  if(k<=0) {
    calB[t][k] = 0;
    calB[n-1-t][k] = 0;
    return ;
  }

  if(calB[t][k]!=-1 && calB[n-1-t][k]!=-1) return;

  int l=0,r=0;
  for(int j=k;j>=1;j--){
    l= (l+nocows(n-1-t,j))%9901;
    r= (r+nocows(t,j))%9901;
  }
  calB[n-1-t][k] = l;
  calB[t][k] = r;
}

int
nocows(int n, int k){
  if(n%2==0 || (2*k-1)>n || n>exp2(k)-1|| k==0) {
    cal[n][k] = 0;
    return 0;
  }
  if(cal[n][k]!=-1) return cal[n][k];
  int most = (n-1)/2;
  int tmp = 0;
  for(int i=1;i<=most;i+=2){
    int left = nocows(i,k-1);
    int right = nocows(n-1-i,k-1);
    calBelow(n,i,k-2);
    int p = i==most?1:2;
    tmp = (tmp+left*right*p+left*calB[n-1-i][k-2]*p+right*calB[i][k-2]*p)%9901;
  }
  cal[n][k] = tmp%9901;
  return cal[n][k];
}

void
solve(){
  cal[1][1] = 1;
  solutions = nocows(n,k);
}

int main() {
  input();
  solve();
  output();
  return 0;
}
