/*
  ID: liu.enz1
  PROG: holstein
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

ofstream fout ("holstein.out");
ifstream fin ("holstein.in");

#define MAX_VIT 25
#define MAX_FEED 15

int vitmains;
int requriements[MAX_VIT] = {0};
int feedTypes;
int feeds[MAX_FEED][MAX_VIT] = {{0}};

void
input(){
  fin>>vitmains;
  for(int i=0;i<vitmains;i++)
    fin>>requriements[i];
  fin>>feedTypes;
  for(int i=0;i<feedTypes;i++)
    for(int j=0;j<vitmains;j++)
      fin>>feeds[i][j];
}

void
output(){
}

void
solve(){
}

int main() {
  input();
  solve();
  output();
  return 0;
}
