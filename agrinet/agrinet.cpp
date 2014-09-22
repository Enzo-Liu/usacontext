/*
  ID: liu.enz1
  PROG: agrinet
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

ofstream fout ("agrinet.out");
ifstream fin ("agrinet.in");

#define MAX 100
#define INF 1e7

int n;
int dist[MAX][MAX];
int len[MAX][MAX];
int next[MAX][MAX];
int answer=INF;

void
input(){
  fin>>n;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      fin>>dist[i][j];
      next[i][j] = j;
    }
}

void
output(){
  fout<<answer<<endl;
}

int lowcost[MAX],closest[MAX];
int prim(int v0)
{
  int i,j,mindis,minone;
  int ans = 0;/*用来记录最小生成树的总长度*/
  /*各点距离初始化*/
  for(i = 0;i < n;i++) {
    lowcost[i] = dist[v0][i];
    closest[i] = v0;
  }
  for(i = 0;i < n-1;i++) {
    mindis = INF;
    for(j = 0;j < n;j++)
      if(lowcost[j] && mindis > lowcost[j]) {
        mindis = lowcost[j];
        minone = j;
      }
    /*将找到的最近点加入最小生成树*/
    ans += lowcost[minone];
    lowcost[minone] = 0;
    /*修正其他点到最小生成树的距离*/
    for(j = 0;j < n;j++)
      if(dist[minone][j] < lowcost[j]) {
        lowcost[j] = dist[j][minone];
        closest[j] = minone;
      }
  }
  return ans;
}
void
solve(){
  answer = prim(0);
}

int main() {
  input();
  solve();
  output();
  return 0;
}
