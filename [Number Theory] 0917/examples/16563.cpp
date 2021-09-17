//
// Created by Kang Minji on 2021-09-17.
//

// 배열 값에 소수 넣기
// 만약 값이 있다면 갱신 X
#include <iostream>
#include <vector>
#include <cmath> // sqrt 사용
using namespace std;

const int SIZE = 5000000;

// 소수 경롤르 저장해서 리턴하는 함수
vector<int> isPrime(){
    vector<int> prime(SIZE, 0);

    // 먼저 모든 수를 소수라 가정하고, i번째 인덱스에 i값 저장
    for(int i=2; i<=SIZE; i++)
        prime[i] = i;

    for (int i=2; i*i<=sqrt(SIZE); i++){
        if (prime[i] == i){ // i가 소수라면
            for (int j=i*i; j<=SIZE; j+=i){ // i의 배수에 소수 i를 저장
                if (prime[j]==j) // 지정된 소수가 없다면
                    prime[j] = i; // 소수 저장
            }
        }
    }
    return prime;
}

int main(){
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    // 입력
    cin >> n;

    // 미리 최대 크기까지의 소수 경로 저장
    vector<int> prime = isPrime();

    while (n--){
        // 소인수분해할 수 입력
        cin >> k;
        // 소인수분해 결과 출력
        while (k > 1){
            cout << prime[k] << ' ';
            k = k/prime[k];
        }
        cout << "\n";
    }
}