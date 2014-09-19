/*
  ID: liu.enz1
  PROG: cowtour
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

ofstream fout ("cowtour.out");
ifstream fin ("cowtour.in");

#define MAX 151
#define MAX_DIST 150000

int num;

typedef struct{
  int x;
  int y;
} Poi;
Poi pois[MAX];

double
dist[MAX][MAX] = {{0}};
int
field[MAX] = {0};
int filedsNum = 0;

double
dis(Poi& a,Poi& b){
  return sqrt((double)((a.x-b.x)*(a.x-b.x))+(double)((a.y-b.y)*(a.y-b.y)));
}

void
input(){
  fin>>num;
  for(int i=0;i<num;i++)
    fin>>pois[i].x>>pois[i].y;
  char s;
  for(int i=0;i<num;i++)
    for(int j=0;j<num;j++){
      dist[i][j]=MAX_DIST;
      fin>>s;
      if(s=='1') {
        dist[i][j] = dis(pois[i], pois[j]);
      }else if(i==j) dist[i][j] =0;
    }
}

bool visited[MAX] = {false};

queue<int> buff;
double
longest[MAX] = {0};
double
fdiam[MAX] = {0};
double res = MAX_DIST;

void
getLongest(){
  for(int k=0; k<num; k++)
    for(int i=0; i<num; i++)
      for(int j=0; j<num; j++)
        if(dist[i][k]+dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k]+dist[k][j];
}

void mark(int i, int m)
{
  int j;
  if(field[i] != 0){
    return ;
  }
  field[i] = m;
  for(j = 0; j < num; j++){
    if(dist[i][j] < MAX_DIST){
      mark(j, m);
    }
  }
}

void
output(){
  fout<<showpoint<<fixed;
  fout<<res<<endl;
}

void
solve(){

  getLongest();

  for(int i=0;i<num;i++)
    if(field[i]==0)
      mark(i,++filedsNum);

  for(int i = 0; i < num; i++){
    for(int j=0;j<num;j++){
      if(longest[i]<dist[i][j]&& dist[i][j]<MAX_DIST)
        longest[i] = dist[i][j];
      // cout<<dist[i][j]<<" ";
    }
    //    cout<<longest[i]<<endl;

    if(fdiam[field[i]] < longest[i] && longest[i]<MAX_DIST){
      fdiam[field[i]] = longest[i];
    }
  }

  for(int i = 0; i < num; i++){
    for(int j = 0; j < num; j++){
      if(field[i] == field[j]){
        continue;
      }

      double t = longest[i] + longest[j] + dis(pois[i], pois[j]);
      if(t < fdiam[field[i]]){
        t = fdiam[field[i]];
      }
      if(t < fdiam[field[j]]){
        t = fdiam[field[j]];
      }

      if(t < res){
        res = t;
      }
    }
  }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
