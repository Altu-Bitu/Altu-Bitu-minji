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

int n, m;
int num[SIZE]; // 수열
bool check[SIZE+1]; // 수 사용 체크 배열

// 재귀함수로 구현한 백트래킹
void backtracking(int cnt){
    // 계속 가지치기 -> promising한 가지에 도달하면 return
    // 나머지 가지는 false로 저장해서 차단함
    if (cnt == m){ // 기저조건, 길이 m인 수열 만든 경우
        for (int i=0; i<cnt; i++) // 바로 출력함
            cout << num[i] << ' ';
        cout << "\n";
        return;
    }
    for (int i=1; i<=n; i++){
        if (!check[i]){ // 현재 수열에 해당 수 없다면
            num[cnt] = i; // 수열에 값 저장
            check[i] = true; // 수 사용
            backtracking(cnt+1); // 다음 수열 인덱스 호출
            check[i] = false; // 원래 상태로 돌려놓음
        }
    }
}

int main(){

    // 입력
    cin >> n >> m;

    // 연산 + 출력
    backtracking(0); // 인덱스 0번부터 시작
}