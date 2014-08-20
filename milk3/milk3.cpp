/*
ID: liu.enz1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX 20

int a,b,c;
ofstream fout ("milk3.out");
ifstream fin ("milk3.in");
bool has[MAX]={false};
bool v[MAX][MAX] = {{false}};

void solve(int ta,int tb,int tc)
{
  cout<<ta<<","<<tb<<","<<tc<<endl;
  if(v[ta][tb]==true) return;
  v[ta][tb] = true;
  if(ta==0)
    has[tc] = true;
  //c->a
  solve((a-ta)>=tc?(ta+tc):a,tb,(a-ta)>=tc?0:(tc-a+ta));

  //c->b
  solve(ta,(b-tb)>=tc?(tb+tc):b,(b-tb)>=tc?0:(tc-b+tb));

  //a->b
  solve((b-tb)>=ta?0:(ta-b+tb),(b-tb)>=ta?(tb+ta):b,tc);

  //b->a
  solve((a-ta)>=tb?(tb+ta):a,(a-ta)>=tb?0:(tb-a+ta),tc);

  //a->c
  solve((c-tc)>=ta?0:(ta-c+tc),tb,(c-tc)>=ta?(tc+ta):c);

  //b->c
  solve(ta,(c-tc)>=tb?0:(tb-c+tc),(c-tc)>=tb?(tc+tb):c);
}

int main() {
  fin>>a>>b>>c;

  solve(0,0,c);

  for(int i=0;i<c;i++)
    if(has[i]==true)
      fout<<i<<" ";

  fout<<c<<endl;

  return 0;
}
