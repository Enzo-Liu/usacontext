/*
  ID: liu.enz1
  PROG: money
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

#define MAX 25
#define MAXMONEY 10000
int v,n;
int coins[MAX];
unsigned long long ways[MAXMONEY+1][MAX+1]={{0}};
unsigned long long solutions;

ofstream fout ("money.out");
ifstream fin ("money.in");
int
compare(const void* a,const void* b){
  return *((int *)a) - *((int *)b);
}

void
input(){
  fin>>v>>n;
  for(int i=0;i<v;i++)
    fin>>coins[i];
  qsort(coins,v,sizeof(int),compare);
}

void
output(){
  fout<<solutions<<endl;
}

unsigned long long
money(int n,int v){
  if(ways[n][v]!= 0) return (int)ways[n][v]==-1?0:ways[n][v];
  if(n==0) return 1;
  if(v==0) return 0;
  int a = n%coins[v-1];
  if(v==1) return a==0?1:0;
  unsigned long long t = 0;
  /** TODO why this two method diff so much ? **/
  //for(int i = 0;i<=n;i+=coins[v-1]){
  //t+=money(n-i,v-1);
  //}
  int l = n-coins[v-1];
  t+= money(n,v-1)+((l<0)?0:money(l,v));
  ways[n][v] = t==0?-1:t;
  return t;
}

void
solve(){
  solutions = money(n,v);
}

int main() {
  input();
  solve();
  output();
  return 0;
}
