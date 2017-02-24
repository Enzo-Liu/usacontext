/*
  ID: liu.enz1
  PROG: runround
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

ofstream fout ("runround.out");
ifstream fin ("runround.in");

unsigned long m ;
unsigned long r ;

void
input(){
  fin>>m;
}

bool
isRunRound(unsigned long n){
  if(n>1000000000) return false;
  char s[20] = {0};
  bool h[10] = {false};
  bool v[10] = {false};
  sprintf(s,"%ld",n);
  int len = strlen(s);
  int cur = 0;
  int state = s[cur] - '0';
  while(h[cur]!=true && cur<len){
    if(state == 0) return false;
    h[cur] = true;
    cur = (cur +state) %len;
    state = s[cur] - '0';
    v[state] = true;
  }

  int count = 0;
  for(int i=0;i<10;i++)
    if(v[i]==true) count++;

  if(count == len ) return true;

  return false;
}

void
output(){
  fout<<r<<endl;
}

void
solve(){
  for(unsigned long i=m+1;;i++)
    if(isRunRound(i)) {
      r = i;break;
    }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
