//
// Created by Kang Minji on 2021-09-26.
//

#include <iostream>
using namespace std;

int constructor(int n){
    // n까지의 분해합 모두 구해보며 분해합이 n인 경우 찾기
    for (int i=1; i<=n; i++){
        int k=i; // i는 가공하면 안되므로 k에 저장
        int sum = i; // 분해합 -> 해당 수
        while(k>0){ // 분해합 -> 각 자리수의 합
            sum += (k % 10);
            k /= 10;
        }
        if (sum == n) // 분해합이 n이라면 바로 생성자(i) 리턴
            return i;
    }
    return 0; // 생성자가 없는 경우
}

int main(){
    int n;

    // 입력
    cin >> n;

    // 연산 + 출력
    cout << constructor(n) << "\n";
}