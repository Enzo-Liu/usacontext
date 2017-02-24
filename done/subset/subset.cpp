/*
  ID: liu.enz1
  PROG: subset
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

ofstream fout ("subset.out");
ifstream fin ("subset.in");

#define MAX 40
#define MAXSUM MAX*(MAX+1)/2

int n;
int solutions;
int res[MAX][MAXSUM];

void
input(){
  fin>>n;
  for(int i=0;i<MAX;i++)
    for(int j=0;j<MAXSUM;j++)
      res[i][j] = -1;
}

void
output(){
  fout<<solutions<<endl;
}

void
findPath(int max,int sum){
  int curSolutions = solutions;
  int curSum = sum;
  if(res[max][curSum]!= -1){
    solutions += res[max][curSum];
    return;
  }
  sum -= max;
  if(0==sum) {
    solutions++;
  }
  if(0>=sum) return;

  int min = sqrt(2*sum);
  for(int i = max-1;i>=min;i--){
    findPath(i,sum);
  }
  res[max][curSum] = solutions - curSolutions;
}

void
solve(){
  int sum = n*(n+1)/2;
  if(sum %2!=0) return;
  sum /=2;
  findPath(n,sum);
}

int main() {
  input();
  solve();
  output();
  return 0;
}
