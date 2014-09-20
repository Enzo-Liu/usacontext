/*
  ID: liu.enz1
  PROG: comehome
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

ofstream fout ("comehome.out");
ifstream fin ("comehome.in");

#define MAX 58
#define INF 1e8

bool
hasCow[MAX] = {false};

int
dist[MAX][MAX] = {{0}};

typedef struct State{
  int dist;
  int pasture;
  friend bool operator < (struct State const &a,struct State const &b)
  {
    if(a.dist!=b.dist)
      return a.dist<b.dist;
    return  a.pasture<b.pasture;
  }
}State;

int
getSymbol(int s){
  if('Y'>=s && s>='A'){
    int t = s-'A'+1;
    hasCow[t] = true;
    return t;
  }
  else if(s=='Z') return s-'A'+1;
  return s-'a'+27;
}

void
input(){
  for(int i=1;i<MAX;i++)
    for(int j=1;j<MAX;j++)
      dist[i][j] = INF;

  int n;fin>>n;
  char ca,cb;
  int td;
  for(int i=0;i<n;i++){
    fin>>ca>>cb>>td;
    int a = getSymbol(ca); int b = getSymbol(cb);
    if(td<dist[a][b]) dist[b][a] = dist[a][b] = td;
  }
}

set<State> states;
int res_p;
int res_d;

void
output(){
  fout<<(char)('A'+res_p-1)<<" "<<res_d<<endl;
}

void
solve(){
  State state;
  int start = getSymbol('Z');
  bool visited[MAX] = {false};
  state.pasture = start;
  state.dist = 0;
  states.insert(state);
  while(!states.empty()){
    State s = *states.begin();
    int now = s.pasture;
    int d = s.dist;
    if(hasCow[now]){
      res_p = now;
      res_d = d;
      break;
    }
    states.erase(states.begin());
    if(visited[now]) continue;
    for(int t=1;t<MAX;t++){
      if(visited[t]) continue;
      if(dist[now][t]<INF){
        dist[start][t] = min(dist[start][t],d+dist[now][t]);
        //cout<<start<<" "<<now<<" "<<t<<" "<<dist[start][t]<<endl;
        State next;next.pasture = t;next.dist = dist[start][t];states.insert(next);
      }
    }
    visited[now] = true;
  }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
