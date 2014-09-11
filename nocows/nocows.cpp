/*
  ID: liu.enz1
  PROG: nocows
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

ofstream fout ("nocows.out");
ifstream fin ("nocows.in");

int n,k;

void
input(){
  fin>>n>>k;
}

void
output(){
  fout<<n<<endl<<k<<endl;
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
