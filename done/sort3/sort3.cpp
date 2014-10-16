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
int swaps[4][4] = {{0}};

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
  fout<<steps<<endl;
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
    int from = (i<count[1]?1:(i<count[1]+count[2]?2:3));
    int to = set[i];
    swaps[from][to] ++;
  }
  for(int i=1;i<=3;i++)
    for(int j=i+1;j<=3;j++){
      int temp = min(swaps[i][j],swaps[j][i]);
      steps+= temp;
      swaps[i][j]-=temp;
      swaps[j][i]-=temp;
    }

  for(int i=1;i<=3;i++)
    for(int j=i+1;j<=3;j++)
      if(swaps[i][j]!=0){
        steps+= 2*swaps[i][j];
        return;
      }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
