/*
ID: liu.enz1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int num,stalls,cows;
int stallMap[50];
int spareMap[50];

void swap(int data[],int i,int j)
{
  int temp = data[i];
  data[i] = data[j];
  data[j] = temp;
}

int partition(int data[],int start,int end)
{
  int key = data[start];
  int i=start,j=end;
  while(i<j) {
    while(data[i]>=key&&i<end) i++;
    while(data[j]<key) j--;
    if(i<j) swap(data,i,j);
  }
  swap(data,start,j);
  return j;
}

void qsort(int data[],int start,int end)
{
  if(start>=end) return;
  int j = partition(data,start,end);
  qsort(data,start,j-1);
  qsort(data,j+1,end);
}

int main() {
  ofstream fout ("barn1.out");
  ifstream fin ("barn1.in");

  fin>>num>>stalls>>cows;
  if(num>=cows) {fout<<cows<<endl;return 0;}
  for(int i=0;i<cows;i++) {
    fin>>stallMap[i];
  }

  qsort(stallMap,0,cows-1);

  for(int i=1;i<cows-1;i++) {
    spareMap[i] = stallMap[i-1] -stallMap[i]-1;
  }

  int left = stallMap[0]+1-stallMap[cows-1];
  spareMap[0] = 0;
  spareMap[cows-1] = 0;

  qsort(spareMap,0,cows-1);

  for(int i=0;i<num-1;i++)
    left -= spareMap[i];

  fout<<left<<endl;

  return 0;
}
