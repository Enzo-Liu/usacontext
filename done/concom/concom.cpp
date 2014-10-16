/*
  ID: liu.enz1
  PROG: concom
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

#define MAX_CORP 101

int n;
int perMap[MAX_CORP][MAX_CORP] = {{0}};

int own[MAX_CORP][MAX_CORP] = {{0}};

set<int> corpSet;
int corps[MAX_CORP];

ofstream fout ("concom.out");
ifstream fin ("concom.in");

void
input(){
  fin>>n;
  int i,j,p;
  for(int t=0;t<n;t++){
    fin>>i>>j>>p;
    perMap[i][j] = p;
    corpSet.insert(i);
    corpSet.insert(j);
  }
  int index = 0;
  for(set<int>::iterator it=corpSet.begin();it!=corpSet.end();it++)
    corps[++index] = *it;

  n = index;
}

void
out(int i){
  for(int t = 1;t<=n;t++)
    if(own[i][corps[t]]==1)
      fout<<i<<" "<<corps[t]<<endl;
}

void
output(){
  for(int i=1;i<=n;i++)
    out(corps[i]);
}

void
update(int i,int j){
  if(own[i][j]==1) return;
  own[i][j] = 1;
  for(int t=1;t<=n;t++){
    if(i==corps[t]||j==corps[t]) continue;
    perMap[i][corps[t]]+=perMap[j][corps[t]];
    if(perMap[i][corps[t]]>50) update(i,corps[t]);
  }
}

void
solve(){
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
      if(j!=i && perMap[corps[i]][corps[j]]>50)
        update(corps[i],corps[j]);
    }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
