/*
  ID: liu.enz1
  PROG: maze1
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

ofstream fout ("maze1.out");
ifstream fin ("maze1.in");

#define MAX_W 2*38+1
#define MAX_H 2*100+1
#define MAX 38*100+1

int w,h;
char map[MAX_H][MAX_W] = {{0}};
int maxW;
int maxH;

int blockNum;
int weight[MAX] = {0};
int visited[MAX] = {0};
int start[2] = {0};
int longest = 0;

int getNum(int i,int j){
  return ((i-1)/2*w+(j+1)/2);
}

int startNum = 0;

void
input(){
  fin>>w>>h;
  maxW = 2*w+1;
  maxH = 2*h+1;
  char c;
  fin.unsetf(ios_base::skipws);
  for(int i=0;i<maxH;i++){
    fin>>c;
    for(int j=0;j<maxW;j++){
      fin>>map[i][j];
      if(i==0 && map[i][j] == ' ')
        start[startNum++] = getNum(i+1,j);
      if(j==0 && map[i][j] == ' ')
        start[startNum++] = getNum(i,j+1);
      if(i==maxH-1 && map[i][j] == ' ')
        start[startNum++] = getNum(i-1,j);
      if(j==maxW-1 && map[i][j] == ' ')
        start[startNum++] = getNum(i,j-1);
    }
  }
  blockNum = w*h;
}

void
output(){
  fout<<longest+1<<endl;
}

void
reset(){
  for(int i =1;i<=blockNum;i++){
    weight[i] = 0;
    visited[i] = 0;
  }
}

//N E S W
int dh[4] = {-2,0,2,0};
int dw[4] = {0,2,0,-2};

int max = 0;
bool
can(int s,int i){
  int nh = (s-1)/w+1;
  int nw = s-(nh-1)*w;
  nh = nh*2-1;
  nw = nw*2-1;
  return nh+dh[i]>=0 && nw +dw[i]>=0 && nh+dh[i]<maxH && nw +dw[i]<maxW
                                                                   && map[nh+dh[i]/2][nw+dw[i]/2]!='-' && map[nh+dh[i]/2][nw+dw[i]/2]!='|';
}

queue<int> qu;

void
move(int s){
  qu.push(s);
  while(!qu.empty()){
    int n = qu.front();
    qu.pop();
    if(visited[n] == 1) continue ;
    int nh = (n-1)/5+1;
    int nw = n-(nh-1)*w;
    nh = nh*2-1;
    nw = nw*2-1;
    for(int i = 0;i<4;i++){
      if(!can(n,i)) continue;
      int ns = getNum(nh+dh[i],nw+dw[i]);
      if(visited[ns] == 1) continue;
      weight[ns] = weight[n]+1;
      cout<<n<<" "<<ns<<" "<<weight[ns]<<endl;
      qu.push(ns);
    }
    visited[n] = 1;
  }
}

void
calFromStart(int s){
  reset();
  weight[s] = 0;
  move(s);
}

void
solve(){
  int res[MAX] = {0};
  for(int i = 0;i<startNum;i++){
    int s = start[i];
    calFromStart(s);
    for(int j=1;j<=blockNum;j++){
      if(i == 0) res[j] = weight[j];
      else res[j] = min(res[j],weight[j]);
    }
  }
  for(int i=1;i<=blockNum;i++){
    longest = longest>res[i]?longest:res[i];
  }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
