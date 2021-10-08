//
// Created by Kang Minji on 2021-09-26.
//

#include <iostream>
using namespace std;

// n번째 종말의 수 확인
int endNumber(int n){
    int cnt = 0; // 종말의 숫자 카운트
    // 666(첫 번째 종말의 숫자)부터 차례로 모두 검사해보기
    for (int i=666;; i++){
        string s = to_string(i);
        if (s.find("666") != s.npos) // "666"이 존재한다면
            cnt++;
        if (cnt == n) // n번째 종말의 숫자
            return i;
    }
}

int main(){
    int n;

    // 입력
    cin >> n;

    // 연산 + 출력
    cout << endNumber(n) << "\n";
}