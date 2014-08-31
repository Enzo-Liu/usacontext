/*
  ID: liu.enz1
  PROG: sort3
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

ofstream fout ("sort3.out");
ifstream fin ("sort3.in");

#define MAX 1000
int n;
int set[MAX] = {0};
int steps = 0;
int count[4] = {0};
int swaps[MAX] = {0};
int swapNum = 0;

void
input(){
  fin>>n;
  for(int i=0;i<n;i++) {
    fin>>set[i];
    count[set[i]]++;
  }
}

void
output(){
  fout<<(swapNum%2==0?swapNum/2:swapNum/2+1)<<endl;
}

void
solve(){
  for(int i=0;i<n;i++) {
    switch (set[i]){
    case 1:
      if(i<count[1]) continue;
      break;
    case 2:
      if(i>=count[1]&&i<count[1]+count[2]) continue;
      break;
    case 3:
      if(i>=count[1]+count[2]) continue;
      break;
    }
    swaps[swapNum++] = i;
  }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
