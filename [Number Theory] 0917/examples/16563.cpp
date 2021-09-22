//
// Created by Kang Minji on 2021-09-17.
//

// 배열 값에 소수 넣기
// 만약 값이 있다면 갱신 X
#include <iostream>
#include <vector>
#include <cmath>
#define SIZE 5000000
using namespace std;

vector<int> isPrime(){
    vector<int> prime(SIZE+1, 0);

    // 일단 모든 수를 소수라 가정하고, i번째 인덱스에 i값 저장
    for (int i=2; i<=SIZE; i++){
        prime[i] = i;
    }

    for (int i=2; i <= sqrt(SIZE); i++){
        if (prime[i] == i){ // i가 소수라면
            // i의 배수에 i를 저장한다
            for (int j=i*i; j<=SIZE; j+=i){
                if (prime[j] == j) // 지정된 소수가 없다면
                    prime[j] = i;
            }
        }
    }
    return prime;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n;
    vector<int> prime = isPrime();

    while(n--){
        cin >> k;

        // 소인수분해 결과 입력
        while(k>1){
            cout << prime[k] << ' ';
            k = k/prime[k];
        }
        cout << "\n";
    }
}