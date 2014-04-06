/*
ID: liu.enz1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int max(int* counts)
{
  return counts[0];
}

int beads(int n,const char* necklace)
{
  int* counts = new int[n];
  int index = 0;
  char last = 0;
  int count = 1;

  for(int i=0;i<n;i++)
  {
    if(necklace[i]==last || necklace[i]=='w')
    {
      count++;
      continue;
    }

    last = necklace[i];
    counts[index]= count;
    index = i;
    count = 1;
  }
  if(counts[n-1]==0&& (necklace[n-1]==necklace[0]||necklace[0]=='w'))
  {
    counts[index]+=counts[0];

  }

  int beads = max(counts);
  delete[] counts;
  return beads;
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int a;
    string b;
    fin >> a >> b;
    fout <<beads(a,b.c_str()) << endl;
    return 0;
}

