/*
  ID: liu.enz1
  PROG: prefix
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

ofstream fout ("prefix.out");
ifstream fin ("prefix.in");

#define MAX_NUM 200
#define MAX_LEN 11
#define MAX_STR_LEN 200001

char str[MAX_STR_LEN] = {0};
int strLen=0;

typedef struct{
  char seq[MAX_LEN];
  int len;
} Primitive;

Primitive eles[MAX_NUM];
int num=0;

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
}

void
output(){
  for(int i=0;i<num;i++)
    cout<<eles[i].seq<<endl;
  cout<<str<<endl;
}


void
solve(){
}

int main() {
  input();
  solve();
  output();
  return 0;
}
