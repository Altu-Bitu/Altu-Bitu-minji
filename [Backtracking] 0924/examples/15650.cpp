//
// Created by Kang Minji on 2021-09-24.
//

#include <iostream>
using namespace std;
#define SIZE 8

int n, m;
int num[SIZE];
//bool check[SIZE+1]; // 오름차순에 중복 체크 조건 포함되어 있음


void backtracking(int cnt, int start){ // 인덱스, 수열 시작 인수
    if (cnt == m){
        for (int i=0; i<cnt; i++)
            cout << num[i] << ' ';
        cout << "\n";
        return;
    }
    for (int i=start; i<=n; i++){ // 오름차순 -> 이전 인덱스는 건들지 않는다!
//        if(!check[i]){ // 중복체크(사용되었는지 확인)
            num[cnt] = 1;
//            check[i] = true; // 사용 여부 체크
            backtracking(cnt + 1, i+1);
//            check[i] = false;
//        }
    }
}

int main(){
    // 입력
    cin >> n >> m;

    // 연산 + 출력
    backtracking(0, 1);
}