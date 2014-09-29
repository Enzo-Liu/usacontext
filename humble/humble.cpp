/*
  ID: liu.enz1
  PROG: humble
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

ofstream fout ("humble.out");
ifstream fin ("humble.in");

#define min(A, B) ( ((A) < (B)) ? (A) : (B) )

const int K_MAX = 100;
const int N_MAX = 100000;

static int N, K;
static long long S[K_MAX + 1] = { 1 };
static int indexMultied[K_MAX + 1] = { 0 };
static int humsize = 0;
static long long hum[N_MAX + 1] = { 1 };

void input()
{
  fin >> K >> N;
  for(int i = 1; i <= K; ++i) {
    fin >> S[i];
  }
  return;
}

void solve()
{
  long long nextHum = 0xffffffff;
  while(humsize != N) {
    nextHum = 0xffffffff;
    for(int i = 1; i <= K; ++i) {
      for(int j = indexMultied[i]; j <= humsize; ++j) {
        if(S[i] * hum[j] > hum[humsize]) {
          nextHum = min(nextHum, S[i] * hum[j]);
          indexMultied[i] = j;
          break;
        }
      }
    }
    ++humsize;
    hum[humsize] = nextHum;
  }

  return;
}
void
output(){
  fout<<hum[N]<<endl;
}

int main() {
  input();
  solve();
  output();
  return 0;
}
