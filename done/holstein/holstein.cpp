/*
  ID: liu.enz1
  PROG: holstein
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stdlib.h>

using namespace std;

ofstream fout ("holstein.out");
ifstream fin ("holstein.in");

#define MAX_VIT 25
#define MAX_FEED 15

int vitmains;
int feedTypes;
int feeds[MAX_FEED][MAX_VIT] = {{0}};

typedef struct{
  int requirements[MAX_VIT];
  int result[MAX_FEED];
  int hasFeed;
  int feedNum;
} State;

State init;
queue<State> stateList;
State result;
bool hasSolved = false;

void
input(){
  fin>>vitmains;
  for(int i=0;i<vitmains;i++)
    fin>>init.requirements[i];
  fin>>feedTypes;
  for(int i=0;i<feedTypes;i++)
    for(int j=0;j<vitmains;j++)
      fin>>feeds[i][j];
  init.hasFeed = -1;
  stateList.push(init);
}

void
output(){
  fout<<result.feedNum;
  for(int i=0;i<result.feedNum;i++)
    fout<<" "<<result.result[i]+1;
  fout<<endl;
}

void trySolve(State state, int feedType){
  for(int i=0;i<MAX_VIT;i++)
    state.requirements[i]-=feeds[feedType][i];

  state.result[state.feedNum++] = feedType;
  state.hasFeed = feedType;

  bool isSolved = true;
  for(int i=0;i<vitmains;i++) {
    if(state.requirements[i]>0)
      isSolved = false;
  }
  hasSolved = isSolved;
  if(isSolved == true){
    result = state;
  }
  else
    stateList.push(state);
}

void
solve(){
  while(!stateList.empty()){
    State cur = stateList.front();
    stateList.pop();
    for(int i=0;i<feedTypes;i++){
      if(hasSolved) return;
      if(cur.hasFeed<i)
        trySolve(cur,i);
    }}
}

int main() {
  input();
  solve();
  output();
  return 0;
}
