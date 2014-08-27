/*
ID: liu.enz1
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int m,n;
int walls[50][50] = {{0}};

ofstream fout ("castle.out");
ifstream fin ("castle.in");

void
getInput(){
  fin>>m>>n;
  for(int i = 0;i<n;i++)
    for(int j = 0;j<m;j++)
      fin>>walls[i][j];
}

void
solve(){

}

int main() {
  getInput();

  solve();

  return 0;
}
