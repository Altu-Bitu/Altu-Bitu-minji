//
// Created by Kang Minji on 2021-09-17.
//

#include <iostream>
using namespace std;

// O(n) 연산
int gcdBad(int a, int b){
    // 두 수 중 더 작은 것을 기준으로 하나씩 감소하여 공약수가 있는지 판단
    for (int i= min(a, b); i>1; i--){
        // 공약수 존재한다면 바로 리턴 -> 최대공약수
        if (a%i == 0 && b%i == 0)
            return i;
    }
    return 1; // 끝까지 없다면 최대공약수 1
}

// 재귀함수로 구현한 유클리드 호제법
int gcdRecursion(int a, int b){
    if (b == 0){ // b가 0이면 a가 최대 공약수
        return a;
    }
    // a % b 구한 후 b와 자리 바꾸어서 호출
    return gcdRecursion(b, a%b);
}

int main(){
    int a, b;

    // 입력
    cin >> a >> b;

    // 연산
    //int g = gcdBad(a, b) // O(n) 함수
    int g = gcdRecursion(max(a, b), min(a,b)); // 왼쪽이 더 커야 함
    int l = (a*b)/g; // 최소공배수

    // 출력
    cout << g << "\n" << l << "\n";
}