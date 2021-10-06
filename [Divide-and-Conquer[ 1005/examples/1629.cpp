//
// Created by Kang Minji on 2021-10-05.
//

#include <iostream>
using namespace std;
typedef long long ll;

// 분할 정복으로 곱셈을 하는 함수
ll divide(int a, int b, int c) {
    // Conquer : b가 1인가?
    if (b == 1)
        return a%c;

    // Divide : 제곱수 나누기
    // b가 짝수일 때
    if (b % 2 == 0) {
        ll sub_problem = divide(a, b / 2, c);
        // Conquer : 곱셈 결과 리턴
        return (sub_problem*sub_problem)%c;
    }
    // b가 홀수일 때
    return (a*divide(a, b-1, c)%c);
}

int main(){
    int a, b, c;

    // 입력
    cin >> a >> b >> c;

    cout << divide(a, b, c);
}