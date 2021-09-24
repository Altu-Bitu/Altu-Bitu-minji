//
// Created by Kang Minji on 2021-09-24.
//

/*
 * 중복 x, 수열 길이가 m
 * 재귀함수 설계 필요(각 수를 넣을 때 이미 수열 내에 있으면 넘어감)
 * -> 기저조건은 길이가 m일 때
 * -> 바로 탐색 이어서 하지 않고 체크 배열 원래대로 돌려놓아야 함
 * */

#include <iostream>
using namespace std;
const int SIZE = 8;

int n, m; // 백트래킹은 전역변수 사용하면 편하다
int num[SIZE];
bool check[SIZE+1];

void backtracking(int cnt){ // cnt : 수열의 인덱스
    if (cnt == m){ // 기저조건
        for (int i=0; i<cnt; i++)
            cout << num[i] << ' ';
        cout << "\n";
        return;
    }
    for (int i=1; i<=n; i++){
        if (!check[i]) {
            num[cnt] = i; // 수열에 값 저장
            check[i] = true; // 수 사용
            backtracking(cnt + 1); // 다음 수열 인덱스 호출
            check[i] = false; // 원래 상태로 돌려놓음
        }
    }
}

int main(){
    // 입력
    cin >> n >> m;

    // 연산
    backtracking(0); // 인덱스 0번부터 시작
}