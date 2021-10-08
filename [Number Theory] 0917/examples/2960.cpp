//
// Created by Kang Minji on 2021-09-17.
//

#include <iostream>
#include <vector>
using namespace std;

// 에라토스테네스의 체에서 k번째 지우는 수를 구하는 함수
int isPrime(int n, int k){
    vector<bool> is_prime(n+1, true); // 초기화
    int cnt = 0; // 카운트 변수
    // 제곱근까지 검사할 경우 반례 : k번쨰 지워지는 수가 제곱근 이상의 소수일 경우
    // 따라서 n까지 돌려야 함
    for (int i=2; i<=n; i++){
        if (is_prime[i]){ // i가 소수라면
            for (int j=i; j<=n; j+=i){ // 시간 단축 : i*i해도 좋다. 그러나 여기 문제에서는 소수도 count 해야 하기 때문에 i
                if (!is_prime[j]) // 이미 지워진 수라면 넘어감
                    continue;
                is_prime[j] = false; // i의 배수를 제거
                if (++cnt == k)
                    return j; // k번째 지우는 수를 return
            }
        }
    }
}

int main(){
    int n, k;

    // 입력
    cin >> n >> k;

    // 연산 + 출력
    cout << isPrime(n, k);

}