//
// Created by Kang Minji on 2021-11-02.
//


#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(vector<int> &belt, int n, int d, int k, int c) {
    vector<int> sushi(d + 1, 0); // 초밥 가짓수 담는 벡터

    //쿠폰으로 먹은 초밥
    int section_sushi = 1; // 초밥 가짓수
    sushi[c]++; // 쿠폰으로 먹은 초밥 먹었다고 표시

    //윈도우 초기화
    for (int i = 0; i < k; i++) { // 연속해서 먹는 접시의 수만큼 먹으면서
        sushi[belt[i]]++; // 나오는 초밥 체크
        if (sushi[belt[i]] == 1) // 새로운 초밥인 경우
            section_sushi++; // 초밥 가짓수 증가
    }

    int ans = section_sushi; // 현재까지 먹은 가짓수 저장
    int left = 0, right = k - 1; // 포인터 변수

    // 쿠폰 말고 진짜로 먹은 초밥 세기
    do { //원형태로 윈도우를 옮겨야 하기 때문에 종료조건은 left가 초기값(=0)이 됐을 때
        sushi[belt[left]]--; // 제일 왼쪽에 있는 초밥 확인 후 제거
        if (!sushi[belt[left]]) // 빙금 뺀 초밥의 종류가 더 이상 윈도우에 없으면
            section_sushi--; // 초밥 가짓수 하나 감소

        //윈도우의 양 끝 이동
        left = (left + 1) % n; // 원형 배열 -> 모듈러 연산
        right = (right + 1) % n; // 원형 배열 -> 모듈러 연산

        sushi[belt[right]]++; // 오른쪽에 있는 초밥 먹기
        if (sushi[belt[right]] == 1) // 새로운 초밥일 경우
            section_sushi++; // 초밥 가짓수 증가

        ans = max(ans, section_sushi); // 먹을 수 있는 초밥 가짓수의 최댓값 구하기
    } while (left); // 포인터가 뒤집히지 않을 경우
    return ans; // 최대 초밥 가짓수 리턴턴
}
/**
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 보석 쇼핑 문제처럼 각 종류별 먹은 초밥의 개수를 세어주기
 */
int main() {
    int n, d, k, c; // n : 접시의 수, d : 초밥의 가짓수, k : 연속해서 먹는 접시의 수, c : 쿠폰 번호

    //입력
    cin >> n >> d >> k >> c;
    vector<int> belt(n, 0); // 벨트 상태 초기화
    for (int i = 0; i < n; i++) // 접시의 수 만큼
        cin >> belt[i]; // 벨트 상태 입력받음

    //연산 & 출력
    cout << chooseSushi(belt, n, d, k, c);
}