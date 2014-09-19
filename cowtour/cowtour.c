/*
  LANG: C
  ID: liu.enz1
  PROG: cowtour
*/
#include <stdio.h>
#include <math.h>

#define INF (1e5)
#define MAX (150)
#define getint(i) scanf("%d", &i)

struct point{
  int x, y;
}point[MAX];
double dis[MAX][MAX];
double diam[MAX];
double fdiam[MAX];
int fie[MAX];
int n;

double getdis(int i, int j)
{
  struct point *a, *b;
  a = &point[i];
  b = &point[j];
  return sqrt((double)(a->x - b->x)*
              (a->x - b->x) +
              (double)(a->y - b->y)*
              (a->y - b->y));
}

void mark(int i, int m)
{
  int j;
  if(fie[i] != 0){
    return ;
  }
  fie[i] = m;
  for(j = 0; j < n; j++){
    if(dis[i][j] < INF){
      mark(j, m);
    }
  }
}

int main(void)
{
  int i, j, k;
  int c, now = 1;
  double t, max;
  freopen("cowtour.in", "r", stdin);
  freopen("cowtour.out", "w", stdout);
  getint(n);
  for(i = 0; i < n; i++){
    getint(point[i].x);
    getint(point[i].y);
  }

  for(i = 0; i < n; i++){
    getchar();
    for(j = 0; j < n; j++){
      c = getchar();
      if(i == j){
        dis[i][j] = 0;
      }else if(c == '0'){
        dis[i][j] = INF;
      }else{
        dis[i][j] = getdis(i, j);
      }
    }
  }

  for(i = 0; i < n; i++){
    if(fie[i] == 0){
      mark(i, now++);
    }
  }

  for(k = 0; k < n; k++)
    for(i = 0; i < n; i++)
      for(j = 0; j < n; j++){
        if(dis[i][j] > dis[i][k] + dis[k][j]){
          dis[i][j] = dis[i][k] + dis[k][j];
        }
      }

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(diam[i] < dis[i][j] && dis[i][j] < INF){
        diam[i] = dis[i][j];
      }
    }
    if(fdiam[fie[i]] < diam[i]){
      fdiam[fie[i]] = diam[i];
    }
  }

  max = INF;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(fie[i] == fie[j]){
        continue;
      }

      t = diam[i] + diam[j] + getdis(i, j);
      if(t < fdiam[fie[i]]){
        t = fdiam[fie[i]];
      }
      if(t < fdiam[fie[j]]){
        t = fdiam[fie[j]];
      }

      if(t < max){
        max = t;
      }
    }
  }
  printf("%.6lf\n", max);
  return 0;
}
