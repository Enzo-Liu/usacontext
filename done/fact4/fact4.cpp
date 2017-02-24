/*
  ID: liu.enz1
  PROG: fact4
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
#define MAX 4220

unsigned long long f[MAX] = {0};
int n;

#define MOST 100000000

ofstream fout ("fact4.out");
ifstream fin ("fact4.in");

void
input(){
  fin >> n;
}

void
output(){
  fout<<f[n]%10<<endl;
}

unsigned long long getNonZero(unsigned long long value){
  if(value%10==0)
    return getNonZero(value/10);
  return value;
}

void
solve(){
  f[1] = 1;
  for(int i = 2;i<=n;i++){
    f[i] = getNonZero((f[i-1]*i)%MOST);
  }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
