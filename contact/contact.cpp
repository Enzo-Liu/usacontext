/*
  ID: liu.enz1
  PROG: contact
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

ofstream fout ("contact.out");
ifstream fin ("contact.in");

#define MAX 200001

int low,high,num;
char data[MAX] = {0};

void
input(){
  fin>>low>>high>>num;
  int i = 0;
  while(!fin.eof()) fin>>data[i++];
}

void
output(){
  cout<<data<<endl;
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
