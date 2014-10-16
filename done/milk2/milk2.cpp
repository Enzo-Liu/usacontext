/*
ID: liu.enz1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

void swap(int* a,int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition( int a[],int b[], int l, int r) {
   int pivot, i, j;
   pivot = a[l];
   i = l; j = r+1;
   while( 1)
   {
    do ++i; while( a[i] <= pivot && i <= r );
    do --j; while( a[j] > pivot );
    if( i >= j ) break;
    swap(a+i,a+j);
    swap(b+i,b+j);
   }
    swap(a+l,a+j);
    swap(b+l,b+j);
   return j;
}

void myQSort( int a[],int b[], int l, int r)
{
   int j;

   if( l < r )
   {
      // divide and conquer
        j = partition( a,b, l, r);
       myQSort( a,b, l, j-1);
       myQSort( a,b, j+1, r);
   }
}

int* milk(int n,int* t,int *p)
{
  int* res = new int[2];
  int begin = t[0]; int spare = 0;int max=p[0];int longest = 0;
  for(int i=0;i<n;i++)
  {
    if(t[i]>max || (t[i]<=max &&i==n-1))
    {
      int temp = t[i]-max;
      spare = spare>temp?spare:temp;
      temp = max-begin;
      longest = longest>temp?longest:temp;
      begin = t[i];
    }
    max = max>p[i]?max:p[i];
  }
  if(n==1) longest = p[0]-t[0];
  res[0]= longest;res[1]=spare;
  return res;
}

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n;
    fin >> n;
    int* t = new int[n];
    int* p = new int[n];
    for(int i=0;i<n;i++)
    {
      fin>>t[i]>>p[i];
    }
    myQSort(t,p,0,n-1);
    int* res = milk(n,t,p);
    fout<<res[0]<<" "<<res[1]<<endl;
    delete[] t;
    delete[] p;
    delete[] res;
    return 0;
}


