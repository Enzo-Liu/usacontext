/*
  ID: liu.enz1
  PROG: fracdec
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <set>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

ofstream fout ("fracdec.out");
ifstream fin ("fracdec.in");

#define MAX 100000

int n,d;
int ipart;
int dpart[MAX];
int loc[MAX]={0};
int dnum=0;
int leave=0;

int
gcd(int a,int b){
  if(b==1) return b;
  if(a%b ==0) return b;
  return gcd(b,a%b);
}

void
input(){
  fin>>n>>d;
  assert(d!=0);
  int gc = gcd(n,d);
  n = n/gc; d = d/gc;
}

#define MAX_PRINT 76

void
output(){
  fout<<ipart<<".";
  if(dnum==0){
    fout<<0<<endl;
    return;
  }
  int cur_size = (ipart==0?1:log(ipart))+1;
  if(leave==0){
    for(int i=0;i<dnum;i++){
      if(cur_size==MAX_PRINT){fout<<endl;cur_size=0;}
      fout<<dpart[i];
      cur_size++;
    }
    fout<<endl;
    return;
  }
  int repeat = loc[leave];
  for(int i=0;i<repeat-1;i++){
    if(cur_size==MAX_PRINT){fout<<endl;cur_size=0;}
    fout<<dpart[i];
    cur_size++;
  }
  if(cur_size==MAX_PRINT){fout<<endl;cur_size=0;}
  fout<<"(";
  cur_size++;
  for(int i=repeat-1;i<dnum;i++){
    if(cur_size==MAX_PRINT){fout<<endl;cur_size=0;}
    fout<<dpart[i];
    cur_size++;
  }
  if(cur_size==MAX_PRINT){fout<<endl;cur_size=0;}
  fout<<")"<<endl;
  cur_size++;
}

void
solve(){
  ipart = n/d;
  leave = n%d;
  while(leave!=0 && loc[leave]==0){
    dpart[dnum++] = leave*10/d;
    loc[leave] = dnum;
    leave = leave*10%d;
  }
  if(leave == 0) return;
}

int main() {
  input();
  solve();
  //cout<<ipart<<" "<<dpart[0]<<" "<<leave<<" "<<dnum<<endl;
  output();
  return 0;
}
