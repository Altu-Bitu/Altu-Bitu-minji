//
// Created by Kang Minji on 2021-09-17.
//

#include <iostream>
using namespace std;

// 재귀함수로 구현한 유클리즈 호제법
int gcdRecursion(int a, int b){
    if (b==0)
        return a;
    // a%b를 구한 후, b와 자리를 바꾸어서 호출
    return gcdRecursion(b, a%b);
}

int main(){
    string s;

    // 입력
    cin >> s;

    // 입력으로부터 n, m 추출하기
    int index= s.find(':'); // ':' 위치 찾기
    int n = stoi(s.substr(0, index - 1)); // ':' 이전의 문자를 숫자로 변경
    int m = stoi(s.substr(index + 1, s.length())); // ':' 이후 문자를 숫자로 변경

    int g = gcdRecursion(max(n, m), min(n, m));

    // 최대공약수 구하기
    cout << n/g << ':' << m/g;
}