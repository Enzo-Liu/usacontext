/*
  ID: liu.enz1
  PROG: kimbits
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

#define MAXN 31
#define MAXL 31

ofstream fout ("kimbits.out");
ifstream fin ("kimbits.in");

int n,l,i;

void
input(){
  fin>>n>>l>>i;
}

void
output(){
}
//00000
//00001
//00010 //00011
//00100 //00101 //00110 //00111
//01000 //01001 //01010 //01011 //01100 //01101 //01110
//10000 //10001 //10010 //10011 //10100 //10101 //10110 //11001 //11010
void
solve(){
}

int main() {
  input();
  solve();
  output();
  return 0;
}
