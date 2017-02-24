/*
  ID: liu.enz1
  PROG: prefix
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

ofstream fout ("prefix.out");
ifstream fin ("prefix.in");

#define MAX_NUM 200
#define MAX_LEN 11
#define MAX_STR_LEN 200001

char str[MAX_STR_LEN] = {0};
int strLen=0;
int res = 0;

typedef struct{
  char seq[MAX_LEN];
} Primitive;

Primitive eles[MAX_NUM];
int num=0;

set<int> states;

int compare(const void * p1,const void * p2){
  Primitive* r1 = (Primitive*) p1;
  Primitive* r2 = (Primitive*) p2;
  return strcmp(r1->seq,r2->seq);
}

void
input(){
  char a[MAX_LEN]={0};
  fin>>a;
  while(a[0]!='.'){
    strcpy(eles[num++].seq,a);
    fin>>a;
  }
  char s[77] = {0};
  while(!fin.eof()){
    memset(s,0,77);
    fin>>s;
    strcpy(str+strLen,s);
    strLen+=strlen(s);
  }
  qsort(eles,num,sizeof(Primitive),compare);
  states.insert(0);
}

void
output(){
  fout<<res<<endl;
}

void
find(char* s,int cur){
  for(int i=0;i<num;i++){
    int cmp = strncmp(eles[i].seq,s,strlen(eles[i].seq));
    if(cmp == 0) {
      int n_cur = cur+strlen(eles[i].seq);
      states.insert(n_cur);
      if(n_cur>res) res = n_cur;
    }
    if(cmp>0) break;
  }
}

void
find(int cur){
  char * s = str+cur;
  find(s,cur);
}

void
solve(){
  while(!states.empty()){
    int cur = *states.begin();
    states.erase(cur);
    find(cur);
  }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
