//
// Created by Kang Minji on 2021-10-01.
//

/* 최소, 최대라는 말이 주로 들어감 */
/* A[i]는 A[i-1]의 배수 조건 => greedy */
#include <iostream>
#include <vector>
using namespace std;

// 필요한 동전 갯수의 최솟값 반환
int coinCnt(int n, int k, vector<int> &coin){
    int cnt = 0; // 필요한 동전 개수
    // i : 동전 인덱스, 큰 동전부터 사용
    for (int i= n-1; i>=0; i--){
        if (k == 0) // 원하는 가치 합을 다 만든 경우
            break;
        if (coin[i] <= k){
            cnt += k/coin[i];
            k = k % coin[i]; // 남은 가치값
        }
    }
    return cnt;
}

int main(){
    int n, k;

    // 입력
    cin >> n >> k;
    vector<int> coin(n, 0);
    for (int i=0; i<n; i++){
        cin >> coin[i];
    }

    // 연산+출력
    cout << coinCnt(n, k, coin);

}
