/*
  ID: liu.enz1
  PROG: wormhole
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

ofstream fout ("wormhole.out");
ifstream fin ("wormhole.in");

#define MAX 12

int n;
long hole[MAX+1][2] = {};
int partner[MAX+1] = {};
int result = 0;
void
input(){
  fin>>n;
  for (int i=1;i<=n;i++)
    fin>>hole[i][0]>>hole[i][1];
}

void
output(){
  fout<<result<<endl;
}

int next(int t){
  if(t == 0) return 0;
  long min = 1000000000;
  int pos = 0;
  for(int next = 1;next<=n;next++){
    if(hole[next][0]>hole[t][0] && hole[next][1] == hole[t][1])
      if(hole[next][0]<min){
        min = hole[next][0];
        pos = next;
      }
  }
  return pos;
}

bool hasCircle(){
  for(int start = 1;start<=n;start++){
    int pos = start;
    for(int count = 1;count<=n;count++){
      //cout<<pos;
      pos= next(partner[pos]);
      //cout<<" "<<pos<<";";
    }
    //cout<<endl;
    if(pos > 0 ) return true;
  }
  return false;
}

int
realSolve(){
  int i;
  int total = 0;
  for(i=1;i<=n;i++)
    if(partner[i]==0)
      break;

  if(i==n+1){
    if(hasCircle()) return 1;
    return 0;
  }

  for(int j = i+1;j<=n;j++){
    if(partner[j]==0){
      partner[i] = j;
      partner[j] = i;
      total+= realSolve();
      partner[i] = partner[j] = 0;
    }
  }
  return total;
}

void
solve(){
  result = realSolve();
}

int main() {
  input();
  solve();
  output();
  return 0;
}
