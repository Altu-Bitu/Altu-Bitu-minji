//
// Created by Kang Minji on 2021-10-09.
//

#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int cnt = 0;

void exploreZ(int row, int col, int range){

    // 기저조건 설정
    if (row == r && col == c){
        cout << cnt;
        return;
    }
    // 1) 해당 영역 내에 r, c가 있는 경우
    // r, c의 하한값 안 넣어주면 메모리 초과 난다 -> (2, 1, 1)일 때 참고
    if (r < row+range && r >= row && c < col+range && c >= col) {
        exploreZ(row, col, range/2); // 1사분면
        exploreZ(row, col+range/2, range/2); // 2사분면(행과 열 구분^^^)
        exploreZ(row+range/2, col, range/2); // 3사분면
        exploreZ(row+range/2, col+range/2, range/2); // 4사분면
    }
    // 2) 해당 영역 내에 r, c가 없는 경우(그냥 더해줘도 됨) -> 탐색도 필요없음
    else
        cnt += range * range;
    return;
}

int main(){

    // 입력
    cin >> n >> r >> c;

    // 연산 + 출력
    exploreZ(0, 0, pow(2, n));
}