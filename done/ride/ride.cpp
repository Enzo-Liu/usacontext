/*
ID: liu.enz1 
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int _hash(string a)
{
  const char* cs = a.c_str();
  int len = a.length();
  int p = 1;
  for(int i=0;i<len;i++)
  {
    p=(cs[i]-'A'+1)*p%47;
  }
  return p;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;
    fout << (_hash(a)==_hash(b)?"GO":"STAY") << endl;
    return 0;
}

