/*
  ID: liu.enz1
  PROG: lamps
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

ofstream fout ("lamps.out");
ifstream fin ("lamps.in");

#define MAX 100

int n,c;

int on[MAX] = {0};
int off[MAX] = {0};
int onNum;
int offNum;

typedef struct{
  bool light[MAX];
  int num;
} Lamps;
#define MAX_RES 8

Lamps res[MAX_RES];
int resNum = 0;

int
compare(const void * l1,const void * l2){
  int i =0;
  while(i<n){
    if(((Lamps*)l1)->light[i]!=((Lamps *) l2)->light[i])
      return ((Lamps*)l1)->light[i] - ((Lamps *) l2)->light[i];
    i++;
  }
  return 0;
}

void
input(){
  fin>>n>>c;
  int t;
  fin>>t;
  while(t != -1){
    on[onNum++] = t;
    fin>>t;
  }
  fin>>t;
  while(t != -1){
    off[offNum++] =t;
    fin>>t;
  }
}

void
out(Lamps& lamps){
  for(int i=0;i<n;i++)
    fout<<lamps.light[i];
  fout<<endl;
}

void
output(){
  if(resNum == 0) {fout<<"IMPOSSIBLE"<<endl; return;}
  qsort(res,resNum,sizeof(Lamps),compare);
  Lamps& last = res[0];
  out(last);
  for(int i=1;i<resNum;i++){
    if(compare(&last,&res[i])){
      out(res[i]);
      last = res[i];
    }
  }
}

void
case0(int c){
  if(c%2==0 && offNum==0) {
    Lamps& lamp = res[resNum++];
    for(int i=0;i<n;i++)
      lamp.light[i] = true;
  }
}

void
case1(){
  if(onNum==0){
    Lamps& lamp = res[resNum++];
    for(int i=0;i<n;i++)
      lamp.light[i] = false;
  }
}

void
case2(){
  for(int i=0;i<offNum;i++)
    if(off[i]%2!=1) return;
  for(int i=0;i<onNum;i++)
    if(on[i]%2!=0) return;

  Lamps& lamp = res[resNum++];
  for(int i=0;i<n;i++)
    if((i+1)%2==0) lamp.light[i] = true;
    else lamp.light[i] = false;
}

void
case3(){
  for(int i=0;i<offNum;i++)
    if(off[i]%2!=0) return;
  for(int i=0;i<onNum;i++)
    if(on[i]%2!=1) return;

  Lamps& lamp = res[resNum++];
  for(int i=0;i<n;i++)
    if((i+1)%2==1) lamp.light[i] = true;
    else lamp.light[i] = false;
}

void
case41(){
  for(int i=0;i<offNum;i++)
    if(off[i]%3==1) return;
  for(int i=0;i<onNum;i++)
    if(on[i]%3!=1) return;

  Lamps& lamp = res[resNum++];
  for(int i=0;i<n;i++)
    if((i+1)%3==1) lamp.light[i] = true;
    else lamp.light[i] = false;
}

void
case42(){
  for(int i=0;i<offNum;i++){
    if(off[i]%2==1 && off[i]%3!=1) continue;
    else if (off[i]%2==0 && off[i]%3==1) continue;
    else return;
  }
  for(int i=0;i<onNum;i++){
    if(on[i]%2==0 && on[i]%3!=1) continue;
    else if (on[i]%2==1 && on[i]%3==1) continue;
    else return;
  }

  Lamps& lamp = res[resNum++];
  for(int i=0;i<n;i++)
    if((i+1)%2==1 && (i+1)%3==1) lamp.light[i] = true;
    else if((i+1)%2==0 && (i+1)%3!=1) lamp.light[i] = true;
    else lamp.light[i] = false;
}

void
case43(){
  for(int i=0;i<offNum;i++){
    if(off[i]%2==0 && off[i]%3!=1) continue;
    else if (off[i]%2==1 && off[i]%3==1) continue;
    else return;
  }
  for(int i=0;i<onNum;i++){
    if(on[i]%2==1 && on[i]%3!=1) continue;
    else if (on[i]%2==0 && on[i]%3==1) continue;
    else return;
  }

  Lamps& lamp = res[resNum++];
  for(int i=0;i<n;i++)
    if((i+1)%2==0 && (i+1)%3==1) lamp.light[i] = true;
    else if((i+1)%2==1 && (i+1)%3!=1) lamp.light[i] = true;
    else lamp.light[i] = false;
}

void
case4(int c){
  if(c%2==0){
    case41();
    case42();
    case43();
  }
  if(c%2 ==1 || c%3==1)
  {
    for(int i=0;i<offNum;i++)
      if(off[i]%3!=1) return;
    for(int i=0;i<onNum;i++)
      if(on[i]%3==1) return;

    Lamps& lamp = res[resNum++];
    for(int i=0;i<n;i++)
      if((i+1)%3==1) lamp.light[i] = false;
      else lamp.light[i] = true;
  }
}

void
solve(){
  case0(c);
  if(c==0) {
    return;
  }
  case1();
  case2();
  case3();
  case4(c);
}

int main() {
  input();
  solve();
  output();
  return 0;
}
