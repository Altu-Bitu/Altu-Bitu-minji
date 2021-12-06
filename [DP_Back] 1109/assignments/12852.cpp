//
// Created by KangMinji on 2021-11-16.
//

#include <iostream>
#include <vector>

using namespace std;

//역추적
vector<int> back(int x, vector<int> &path) { //x = n부터 역추적 시작
    vector<int> result(0); // 포함된 숫자 저장
    while (x != 0) { // 시작 지점 나올 때까지
        result.push_back(x); // 역추적한 값 저장
        x = path[x]; // 다음 경로로 갱신
    }
    return result; // 역추적한 값 리턴
}

//1로 만드는 최소 연산 횟수 리턴
int makeOne(int n, vector<int> &path) {
    vector<int> dp(n + 1, 0); // (i에 가능한 연산을 적용한 수 중 최소 연산 횟수) + 1

    for (int i = 2; i <= n; i++) { // dp 연산 수행
        int min_value = dp[i - 1]; //우선 i - 1 연산 적용한 것으로 저장
        path[i] = i - 1; // i-1 연산 적용한 버전의 최소 연산 횟수
        if (!(i % 3) && min_value > dp[i / 3]) { // 3으로 나눌 수 있고 현재 최소 연산 횟수보다 연산 적게 가능한 경우
            min_value = dp[i / 3]; // 3으로 나눠서 갱신
            path[i] = i / 3; // 최소 연산 횟수 갱신
        }
        if (!(i % 2) && min_value > dp[i / 2]) { // 2로 나눌 수 있고 현재 최소 연산 횟수보다 연산 적게 가능한 경우
            min_value = dp[i / 2]; // 2로 나눠서 갱신
            path[i] = i / 2; // 최소 연산 횟수 갱신
        }
        dp[i] = min_value + 1; // 위에서 i-1 연산 적용했으므로 +1
    }
    return dp[n]; // (n에 가능한 연산을 적용한 수 중 최소 연산 횟수) + 1
}

/**
 * 기본 문제: 1로 만들기
 *
 * [점화식]
 * dp[i] = (i에 가능한 연산을 적용한 수 중 최소 연산 횟수) + 1
 * dp[i] = min(dp[i / 3], dp[i / 2], dp[i - 1]) + 1
 *
 * [역추적]
 * path: 인덱스가 정수를 나타냄, 해당 수에서 연산을 적용한 다음 수를 저장
 * n부터 역추적 시작
 */

int main() {
    int n; // 자연수 N

    //입력
    cin >> n;
    vector<int> path(n + 1, 0); //경로 저장

    //연산
    int ans = makeOne(n, path);
    vector<int> result = back(n, path); // n을 1로 만드는 방법에 포함되어 있는 수

    //출력
    cout << ans << '\n'; // 연산 횟수의 최솟값
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' '; // 순서대로 출력
    return 0;
}