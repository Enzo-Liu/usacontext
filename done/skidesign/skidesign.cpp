/*
  ID: liu.enz1
  PROG: skidesign
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <set>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

ofstream fout ("skidesign.out");
ifstream fin ("skidesign.in");

#define MAX 1000
#define LIMIT 17

int n;
int height[MAX+1];
int cost;

void
input(){
  fin>>n;
  for(int i= 1;i<=n;i++)
    fin>>height[i];
}

void
output(){
  fout<<cost<<endl;
}

bool comp(int a, int b){
  return a<b;
}
int square(int a){
  return a*a;
}
void
solve(){
  sort(height+1,height+n+1,comp);
  int min = -1;
  int low = height[1];
  int high = low+LIMIT;
  for(;high<height[n];low++,high++){
    int c = 0;
    for(int i = 1;height[i]<low;i++)
      c+= square(low - height[i]);
    for(int i = n;height[i]>high;i--)
      c+= square(height[i]-high);

    if(min == -1) min = c;
    else min = min<c?min:c;
  }
  cost = min==-1?0:min;
}

int main() {
  input();
  solve();
  output();
  return 0;
}
