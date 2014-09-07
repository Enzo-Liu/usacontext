/*
  ID: liu.enz1
  PROG: preface
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stdlib.h>

using namespace std;

ofstream fout ("preface.out");
ifstream fin ("preface.in");

#define MAX 3500
int n;
typedef struct{
  int i,v,x,l,c,d,m;
} Count;

Count counts[MAX];
Count tens[10];
Count hundreds[10];
Count thousands[10];
int is=0,vs=0,xs=0,ls=0,cs=0,ds=0,ms=0;

int x[10] = {0,1,2,3,1,0,1,2,3,1};
int y[10] = {0,0,0,0,1,1,1,1,1,0};
int z[10] = {0,0,0,0,0,0,0,0,0,1};

void
initCount(Count& count){
  count.i = 0;
  count.v = 0;
  count.x = 0;
  count.l = 0;
  count.c = 0;
  count.d = 0;
  count.m = 0;
}

void
input(){
  fin >> n;
}

void
output(){
  if(is!=0) fout<<"I "<<is<<endl;
  if(vs!=0) fout<<"V "<<vs<<endl;
  if(xs!=0) fout<<"X "<<xs<<endl;
  if(ls!=0) fout<<"L "<<ls<<endl;
  if(cs!=0) fout<<"C "<<cs<<endl;
  if(ds!=0) fout<<"D "<<ds<<endl;
  if(ms!=0) fout<<"M "<<ms<<endl;
}

/*generate count for the number 'num' */
void genCount(int num){
  int n = num;
  initCount(counts[num]);
  int th = n/1000;
  n -= th*1000;
  int hu = n/100;
  n -= hu*100;
  int te = n/10;
  int si = n - te*10;
  counts[num].i += x[si];
  counts[num].v += y[si];
  counts[num].x += x[te]+z[si];
  counts[num].l += y[te];
  counts[num].c += x[hu]+z[te];
  counts[num].d += y[hu];
  counts[num].m += z[hu]+x[th];
}

void
solve(){
  for(int i =1;i<=n;i++){
    genCount(i);
    is += counts[i].i;
    vs += counts[i].v;
    xs += counts[i].x;
    ls += counts[i].l;
    cs += counts[i].c;
    ds += counts[i].d;
    ms += counts[i].m;
  }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
