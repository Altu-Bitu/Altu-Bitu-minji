//
// Created by Kang Minji on 2021-10-05.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e9; // 최댓값

// 현재 가치(k)를 만드는 동전 개수의 최솟값 리턴하는 함수
int knapsackCoin(int n, int k, vector<int> &coin) {
    vector<int> dp(k + 1, INF); // 각 가치를 만드는 동전 개수의 최솟값 저장하는 벡터, 일단 최댓값으로 초기화한다

    dp[0] = 0; // 가치 0을 만드는 경우 초기화
    for (int i = 0; i < n; i++) { // 동전의 종류(n)개만큼
        for (int j = coin[i]; j <= k; j++) { //!생각해보기! 배낭 문제에서의 1차원 dp구현과 다른 점은?
// 배낭 문제 -> 해당 물품 합친 무게보다 "작아도 괜찮다"
// 동전 문제 -> 해당 가치와 "동일"해야 한다
            if (dp[j - coin[i]] != INF) // dp 점화식에 사용될 값이 업데이트된 값일 경우
                dp[j] = min(dp[j], dp[j - coin[i]] + 1); // 최솟값 업데이트
        }
    }

    if (dp[k] == INF) // 해당 가치가 업데이트 되지 않은 경우(불가능한 경우)
        return -1; // -1 출력한다
    return dp[k]; // 가치 만들 수 있는 경우는 해당 가치를 리턴한다
}

/**
 * 배낭 문제(12865)와 유사
 * 현재 가치를 만드는 동전 개수의 최솟값 저장
 * = max(기존 값, [현재 가치 - 현재 사용하려는 동전 가치]의 동전 개수 최솟값 + 1)
 *
 * !주의! 최솟값을 찾는 문제이므로 dp 배열 초기화 중요
 * !주의! 배낭 문제와 다르게, 꼭 현재 가치를 정확하게 만드는 경우만 검사해야함
 */

int main() {
    int n, k; // n : 동전의 종류, k : 동전 총합

    //입력
    cin >> n >> k;
    vector<int> coin(n, 0); // 각 동전의 가치를 저장하는 벡터 초기화
    for (int i = 0; i < n; i++) // n개만큼
        cin >> coin[i]; // 각 동전의 가치 입력받는다

    //연산 + 출력
    cout << knapsackCoin(n, k, coin) << '\n';

    return 0;
}