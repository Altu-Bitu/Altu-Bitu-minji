//
// Created by Kang Minji on 2021-09-24.
//

#include <iostream>
#define SIZE 15
using namespace std;

int n, ans=0;
int check_col[SIZE]; // 열 체크
bool check_left[SIZE*2], check_right[SIZE*2]; // 좌하향, 우하향 대각선 체크

void backtracking(int cnt){ // cnt : 행
    // 기저조건 : n개의 퀸이 모두 놓임
    if (cnt == n){
        ans++;
        return;
    }
    // 어느 열에 배치할 지 확인
    for(int i=0; i<n; i++){ // i : 열
        if (!check_col[i] && !check_left[cnt + i] && !check_right[cnt - i + n]){
            // 해당 열, 좌하향 대각선, 우하향 대각선에 더 이상 퀸을 놓을 수 없도록 함
            check_col[i] = true;
            check_left[cnt+i] = true;
            check_right[cnt-i+n] = true;
            backtracking(cnt + 1); // 다음 행 호출

            // 재탐색 가능하도록 체크 배열 원래 상태로 돌려주기
            check_col[i] = false;
            check_left[cnt+i] = false;
            check_right[cnt-i+n] = false;
        }
    }
}

int main(){
    // 입력
    cin >> n;

    // 연산
    backtracking(0);

    // 출력
    cout << ans;
}