/*
ID: liu.enz1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define MAX 1000

int r;
int len;
int nums[MAX*(MAX+1)/2];

ofstream fout ("numtri.out");
ifstream fin ("numtri.in");

void calculate(int cr){
  if(cr==0) return;
  int start = (cr-1)*(cr-2)/2;
  int end = (cr-1)*cr/2-1;
  int cur = end+1;
  for(int i =start;i<=end;i++ ) {
    nums[i] += max(nums[cur],nums[cur+1]);
    cur = cur+1;
  }
  calculate(cr-1);
}

int main() {

  fin>>r;
  len = r*(r+1)/2;
  for(int i=0;i<len;i++)
    fin>>nums[i];

  calculate(r);

  fout<<nums[0]<<endl;

  return 0;
}
