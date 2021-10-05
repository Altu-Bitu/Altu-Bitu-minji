//
// Created by Kang Minji on 2021-10-05.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e6 + 1; // 집을 칠하는 maximum 값

vector<vector<int>> cost; // 집을 칠하는 비용 저장

// 요구사항을 만족하면서 모든 집을 칠하는 경우의 수 구하는 함수
int paintDp(int n) {
    // 동적 배열 생성
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));

    //i번째 집을 각각의 색으로 칠하는 최소 비용
    for (int i = 1; i <= n; i++) {
        dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]); // 빨간색으로 칠하는 경우 최소 비용
        dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]); // 초록색으로 칠하는 경우 최소 비용
        dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]); // 파란색으로 칠하는 경우 최소 비용
    }

    int ans = INF; // 일단 최대로 답 잡아놓음
    for (int i = 0; i < 3; i++) // 빨강, 초록, 파랑색으로 칠하는 경우 중
        ans = min(ans, dp[n][i]); // 최소 비용을 찾는다

    return ans; // 최소 비용 리턴
}

/**
 * 앞 뒤의 집의 색이 서로 달라야 한다.
 * 1번 집부터 시작해서 이전 집과 다른 색을 계속 골라주면 자동으로 앞 뒤 집의 색이 서로 달라진다
 * 따라서, 각 집에 대해 각각 3가지 색을 선택한 경우의 최솟값을 계속 저장하며 풀자
 *
 * dp[i][빨간색] = min(dp[i-1][초록색], dp[i-1][파란색]) + 비용[i][빨간색]
 * dp[i][초록색] = min(dp[i-1][빨간색], dp[i-1][파란색]) + 비용[i][초록색]
 * dp[i][파란색] = min(dp[i-1][빨간색], dp[i-1][초록색]) + 비용[i][파란색]
 */

int main() {
    int n; // 집의 개수

    //입력
    cin >> n; // 집의 개수 입력
    cost.assign(n + 1, vector<int>(3, 0)); // 빨, 초, 파로 칠하는 비용 벡터로 저장
    for (int i = 1; i <= n; i++) { // n개의 집을
        for (int j = 0; j < 3; j++) { // r, g, b로 칠하는 비용
            cin >> cost[i][j]; // 입력받는다
        }
    }

    //연산 + 출력
    cout << paintDp(n) << '\n';

    return 0;
}