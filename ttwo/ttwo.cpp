/*
  ID: liu.enz1
  PROG: ttwo
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

ofstream fout ("ttwo.out");
ifstream fin ("ttwo.in");
#define LEN 10

char map[LEN][LEN];
typedef struct{
  int i;
  int j;
  int di;
  int dj;
} Pos;

Pos farmer;
Pos cow;

void
input(){
  for(int i=0;i<LEN;i++)
    for(int j=0;j<LEN;j++){
      fin>>map[i][j];
      if(map[i][j]=='C'){
        cow.i = i;
        cow.j = j;
        cow.di = -1;cow.dj = 0;
      }
      if(map[i][j]=='F'){
        farmer.i = i;
        farmer.j = j;
        farmer.di = -1;farmer.dj = 0;
      }
    }
}
void
rotate(Pos& pos){
  //N
  if(pos.di == -1 && pos.dj == 0){
    pos.di = 0;pos.dj = 1;
  }
  //E
  else if(pos.di == 0 && pos.dj == 1){
    pos.di = 1;pos.dj = 0;
  }
  //S
  else if(pos.di == 1 && pos.dj == 0){
    pos.di = 0;pos.dj = -1;
  }
  //W
  else{
    pos.di = -1 ;pos.dj = 0;
  }
}

int
move(Pos& pos){
  int ni = pos.i+pos.di;
  int nj = pos.j+pos.dj;
  if(ni<0||ni>=LEN||nj<0||nj>=LEN||map[ni][nj] == '*'){
    return -1;
  }else{
    pos.i = ni;
    pos.j = nj;
  }
  return 0;
}

bool hasSolved = false;
int t = 0;

void
output(){
  fout<<(hasSolved?t:0)<<endl;
}

void
solve(){
  //if they are about to meet,it should be less than 160000
  while(!hasSolved && t<=1000000){
    if(farmer.i==cow.i && farmer.j==cow.j){
      hasSolved = true;
    }else{
      if(-1 == move(farmer)) rotate(farmer);
      if(-1 == move(cow)) rotate(cow);
      t++;
    }
  }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
