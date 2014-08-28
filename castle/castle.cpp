/*
  ID: liu.enz1
  PROG: castle
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int m,n;
int walls[50][50] = {{0}};
int* visit[50][50] = {{NULL}};
int rooms[2500] = {0};
int roomNum = 0;
int maxRoom = 0;
int biggestAfterRemove = 0;
char removeInfo[3];

ofstream fout ("castle.out");
ifstream fin ("castle.in");

void
getInput(){
  fin>>m>>n;
  for(int i = 0;i<n;i++)
    for(int j = 0;j<m;j++)
      fin>>walls[i][j];
}
bool
west(int n){
  return n&0b0001;
}

bool
north(int n){
  return n&0b0010;
}

bool
east(int n){
  return n&0b0100;
}

bool
south(int n){
  return n&0b1000;
}

void
calRec(int i,int j,int& size){
  if(visit[i][j] != NULL) return;
  size += 1; visit[i][j] = &size;

  if(!south(walls[i][j])) calRec(i+1,j,size);
  if(!north(walls[i][j])) calRec(i-1,j,size);
  if(!east(walls[i][j])) calRec(i,j+1,size);
  if(!west(walls[i][j])) calRec(i,j-1,size);
}

void
calculateSize(int i,int j){
  calRec(i,j,rooms[roomNum]);
  if(rooms[roomNum]==0)
    return;

  if(maxRoom<rooms[roomNum]) maxRoom = rooms[roomNum];
  roomNum++;
}

void
record(int i,int j,int res,char direct){
  if(biggestAfterRemove<res){
    biggestAfterRemove = res;
    removeInfo[0] = i+1;
    removeInfo[1] = j+1;
    removeInfo[2] = direct;
  }
}

void
solve(){
  //calculate room size
  for(int i=n-1;i>=0;i--)
    for(int j=0;j<m;j++){
      if(visit[i][j]!=NULL) continue;
      calculateSize(i,j);
    }
  //get the wall to be removed
  for(int j=0;j<m;j++)
    for(int i=n-1;i>=0;i--){
      if(i>0 && visit[i][j]!=visit[i-1][j])
        record(i,j,*visit[i][j]+*visit[i-1][j],'N');

      if(j<m-1 && visit[i][j+1]!=visit[i][j])
        record(i,j,*visit[i][j+1]+*visit[i][j],'E');
    }
}

void
output(){
  fout<<roomNum<<endl;
  fout<<maxRoom<<endl;
  fout<<biggestAfterRemove<<endl;
  fout<<(int)removeInfo[0]<<" "<<(int)removeInfo[1]<<" "<<removeInfo[2]<<endl;
}

int main() {
  getInput();
  solve();
  output();

  return 0;
}
