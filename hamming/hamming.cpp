/*
  ID: liu.enz1
  PROG: hamming
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <math.h>
#include <stdlib.h>

using namespace std;

ofstream fout ("hamming.out");
ifstream fin ("hamming.in");
int n,b,d;
int most;

#define MAX 64

typedef struct{
  int set[MAX];
  int num;
} Result;

Result result;

void
input(){
  fin>>n>>b>>d;
  most = pow(2,b);
}

int count1(int c){
  if(c<0) return 0;
  int count = 0;
  while (c!=0){
    if(c&1) count++;
    c = c >> 1;
  }
  return count;
}

int
hd(int a ,int b){
  int res = a^b;
  return count1(res);
}

void
output(){
  for(int i=0;i<result.num;i++){
    fout<<result.set[i];
    if(i!=0&&(i+1)%10==0) fout<<endl;
    else if((i+1)!=result.num) fout<<" ";
  }
  if(result.num%10!=0) fout<<endl;
}

bool
fit(int num,int count,int* res){
  for(int i=0;i<count;i++)
    if(hd(num,res[i])<d)
      return false;

  return true;
}

bool findSet(int base){
  Result temp;
  temp.num = 0;
  temp.set[temp.num++] = base;
  for(int i=base+1;i<=most;i++)
    if(temp.num<n &&fit(i,temp.num,temp.set))
      temp.set[temp.num++] = i;

  if(temp.num==n){
    result = temp;
    return true;
  }
  return false;
}

void
solve(){
  for(int i=0;i<=most;i++){
    if(findSet(i)) break;
  }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
