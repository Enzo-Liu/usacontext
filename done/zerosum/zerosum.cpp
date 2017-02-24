/*
  ID: liu.enz1
  PROG: zerosum
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

ofstream fout ("zerosum.out");
ifstream fin ("zerosum.in");

#define MAX 9

int n;

int resNum=0;

typedef struct {
  char opers[MAX];
} Seq;

void
input(){
  fin>>n;
}

void
output(){
}

int cal(Seq& seq){
  int last = 1; int cur = 0;
  char lastOper = ' ';
  for(int i=0;i<n;i++){
    if(seq.opers[i]==' ') last = last*10+(i+1);
    else{
      if(lastOper == '+') cur+=last;
      if(lastOper == '-') cur-=last;
      last = i+1;
      lastOper = seq.opers[i];
    }
  }
  if(lastOper == '+') cur+=last;
  if(lastOper == '-') cur-=last;
  if(lastOper == ' ') cur=last;
  return cur;
}

void out(Seq & seq){
  for(int i=1;i<n;i++)
    fout<<i<<seq.opers[i];
  fout<<n<<endl;
}

void
zero(Seq seq,int cur){
  if(cur==n) return;

  zero(seq,cur+1);
  seq.opers[cur] = '+';
  if(cal(seq)==0) out(seq);
  zero(seq,cur+1);
  seq.opers[cur] = '-';
  if(cal(seq)==0) out(seq);
  zero(seq,cur+1);
}

void
solve(){
  Seq seq;
  seq.opers[0] = '+';
  for(int i=1;i<n;i++)
    seq.opers[i] = ' ';

  if(cal(seq) == 0) out(seq);
  zero(seq,1);
}

int main() {
  input();
  solve();
  output();
  return 0;
}
