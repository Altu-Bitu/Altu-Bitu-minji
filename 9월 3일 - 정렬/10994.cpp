// 10994번 : 별 찍기 - 19
#include <iostream>
using namespace std;
char star[400][400];


void solution(int x, int y, int n){
  int line = 4*(n-1);

  /* 4ms 느림
  if (n==1){
    star[x][y] = '*';
    return;
  }*/
  if (n==0)
    return;
  for (int i=0; i<line+1; i++){
    for (int j=0; j<line+1; j++){
      // 꽉 찬 라인(맨 위, 아래)
      // 행
      if (i==0 || i==line){
        star[x+i][y+j] = '*';
        continue;
      } 
      // 열
      if (j==0 || j==line) {
        star[x+i][y+j] = '*';
        continue;
      }
      star[x+i][y+j] = ' ';
    }
  }
  solution(x+2, y+2, n-1);
}

int main(){
  int n, line;
  cin >> n;
  solution(0, 0, n);

  line = 4*(n-1);
  for (int i=0; i<line+1; i++){
    for (int j=0; j<line+1; j++){
      cout << star[i][j];
    }
    cout << "\n";
  }
}