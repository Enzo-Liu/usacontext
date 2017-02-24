/*
  ID: liu.enz1
  PROG: stamps
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define MAXK 200
#define MAXN 50

ofstream fout ("stamps.out");
ifstream fin ("stamps.in");

int k,n;
int values[MAXN];
int result;

int comp(void const * a,void const *b){
  return (*(int *) a) - (*(int *)b);
}

void
input(){
  fin>>k>>n;
  for(int i=0;i<n;i++)
    fin>>values[i];

  qsort(values,n,sizeof(int),comp);
}

void
output(){
  fout<<result<<endl;
}

int
hasSolu(int amount,int start,int limit){
  if(amount == 0) return k-limit;
  if(limit == 0 || amount<0) return -1;
  if(amount> limit*values[n-1]) return -2;
  if(amount> limit*values[n-start-1]) return -1;

  while(amount<values[n-start-1]){
    start++;
    if(start == n) return -1;
  }

  for(int i=n-start-1;i>=0;i--){
    int steps = hasSolu(amount-values[i],start,limit-1);
    if(-2 == steps)
      return steps;

    if(-1 != steps)
      return steps;
  }
  return -1;
}

bool
achievable(int amount){
  if(amount > values[n-1]*k) return false;
  int steps = hasSolu(amount,0,k);
  if(steps > 0){
    return true;
  }
  return false;
}

//**all the above is just crap...**
int f[2000000];
//using F[i] = min{F[i-values[j]] j in 1,2...n && i>values[j]} + 1
//get the min F[i] that F[i]>k then i-1 is the answer.

void
solve(){
  f[0] = 0;
  int max = values[n-1]*k;
  int i;
  for(i =1;i<=max;i++){
    for(int j = 0;j<n;j++){
      if(i<values[j])
        break;
      if(f[i] == 0)
        f[i] = f[i-values[j]]+1;
      else
        f[i] = (f[i-values[j]]+1)<f[i]?(f[i-values[j]]+1):f[i];
    }
    if(f[i]>k)
      break;
  }
  result = i-1;

  //this method is too slow
  // while(true){
  //   if(!achievable(result+1))
  //     break;
  //   result++;
  // }
}

int main() {
  input();
  solve();
  output();
  return 0;
}
