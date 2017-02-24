/*
  ID: liu.enz1
  PROG: contact
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include <math.h>

using namespace std;

//print is hard...
#define MOST 8192+1

ofstream fout ("contact.out");
ifstream fin ("contact.in");

#define MAX 200001

int pows[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};

int low,high,num;
int dataLen;
char data[MAX] = {0};
int result[MOST] = {0};
int hlimit = 0;
int llimit = 0;

void pp(int n){
  char bin[13] = {0};
  int pos = 0;
  while(n!=0){
    if(n%2==1){
      n= (n-1)/2;
      bin[pos++] = '1';
    }else{
      n = n/2;
      bin[pos++] = '0';
    }
  }
  for(int i=pos-2;i>=0;i--){
    fout<<bin[i];
  }
}

void
input(){
  fin>>low>>high>>num;
  dataLen = 0;
  while(!fin.eof()) fin>>data[dataLen++];
  llimit = pow(2,low);
  hlimit = pow(2,high+1)+1;
}

typedef struct{
  int pattern;
  int number;
} Pattern;

Pattern patterns[MOST];
int comp(const void * a,const void * b){
  Pattern *pa = (Pattern*)b;
  Pattern *pb = (Pattern*)a;
  if(pa->number != pb->number)
    return pa->number - pb->number;
  return pb->pattern - pa->pattern;
}

void
output(){
  int patternNumber = 0;
  //cout<<endl;
  for(int i = llimit;i<=hlimit;i++){
    if(result[i]!=0){
      patterns[patternNumber].pattern = i;
      patterns[patternNumber].number = result[i];
      patternNumber++;
    }
    //cout<<i<<" "<<result[i]<<endl;
  }
  //cout<<dataLen<<endl;
  qsort(patterns,patternNumber,sizeof(Pattern),comp);
  int curNum = patterns[0].number;
  fout<<curNum<<endl;
  int pnum = 0;
  int total = 0;

  int i = 0;
  for(;i<patternNumber;i++){
    int p =patterns[i].pattern;
    int n =patterns[i].number;
    if(n != curNum){
      fout<<endl;
      total ++;
      if(total == num ) return;
      fout<<n<<endl;
      curNum = n;
      pnum = 0;
    }
    if(pnum==6){
      fout<<endl;
      pnum = 0;
    }
    if(pnum !=0) fout<<" ";
    pp(p);
    pnum++;
  }
  fout<<endl;
}

int
getInt(char * start,int len){
  int res = 0;
  for(int i=0;i<len;i++)
    res += start[len-i-1]=='0'?0:pows[i];
  res+= pows[len];
  return res;
}

void
scan(int pos){
  if(data[pos]!='0' && data[pos]!='1')
    return;
  //cout<<endl;
  for(int len = low;len<=high;len++){
    if(pos+1<len) return;
    int val = getInt(data+(pos+1-len),len);
    // cout<<val<<" ";
    result[val]++;
  }
}

void
solve(){
  for(int i= 0;i<dataLen;i++)
    scan(i);

}

int main() {
  input();
  solve();
  output();
  return 0;
}
