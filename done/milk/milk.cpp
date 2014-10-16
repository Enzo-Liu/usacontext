/*
ID: liu.enz1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int total;
int farmerNum;
struct Farmer{
  int price;
  int amount;
};
int cost = 0;

Farmer farmers[5000];

void swap(Farmer* a,Farmer* b)
{
  Farmer temp = *a;
  *a = *b;
  *b = temp;
}

int partition(Farmer a[], int l, int r) {
  int i, j;
  Farmer pivot = a[l];
  i = l; j = r+1;
  while( 1)
  {
    do ++i; while( a[i].price <= pivot.price && i <= r );
    do --j; while( a[j].price > pivot.price );
    if( i >= j ) break;
    swap(a+i,a+j);
  }
  swap(a+l,a+j);
  return j;
}

void myQSort(Farmer a[], int l, int r)
{
  int j;

  if( l < r )
  {
    // divide and conquer
    j = partition( a, l, r);
    myQSort( a, l, j-1);
    myQSort( a, j+1, r);
  }
}

int main() {
  ofstream fout ("milk.out");
  ifstream fin ("milk.in");
  fin >> total >> farmerNum;
  for(int i=0;i<farmerNum;i++)
    fin>>farmers[i].price>>farmers[i].amount;

  myQSort(farmers,0,farmerNum-1);

  int index = 0;
  int left = total;
  while(left != 0)
  {
    if(farmers[index].amount>=left)
    {
      cost += left*farmers[index].price;
      left = 0;
      continue;
    }
    cost += farmers[index].price*farmers[index].amount;
    left -= farmers[index].amount;
    index++;
  }
  fout<<cost<<endl;

  return 0;
}

