/*
ID: liu.enz1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX 10

int len;
int hasNum[MAX] = {0};
int nums[MAX] = {0};
int solutions = 0;

bool isInSub(int n){
  if(n == 0) return true;

  int t = n%10;
  if(hasNum[t]==1)
    return isInSub((n-t)/10);

  return false;
}

void isSolutions(int aTotal,int d,int e)
{
  int p1 = aTotal*d;
  int p2 = aTotal*e;
  int sum = p1*10+p2;
  if(p1>=1000||p2>=1000||sum>=10000) return;
  if(isInSub(p1)&&isInSub(p2)&&isInSub(sum)){
    solutions++;
  }
}

void isSolutions(int a){
  int i=0,j=0;
  int d,e;
  while(i<len){
    d = nums[i];
    while(j<len){
      e = nums[j];
      isSolutions(a,d,e);
      j++;
    }
    i++;j=0;
  }
}

void countSolutions(){
  int i=0,j=0,k=0;
  int a,b,c;
  while(i<len) {
    a = nums[i];
    while(j<len){
      b = nums[j];
      while(k<len){
        c = nums[k];
        cout<<a<<b<<c<<endl;
        isSolutions(100*a+10*b+c);
        k++;
      }
      j++;k=0;
    }
    i++;j=0;k=0;
  }
}

int main() {
  ofstream fout ("crypt1.out");
  ifstream fin ("crypt1.in");
  fin>>len;
  int temp;
  for(int i=0;i<len;i++){
    fin>>temp;
    nums[i] = temp;
    hasNum[temp] = 1;
  }

  countSolutions();
  fout<<solutions<<endl;

  return 0;
}
