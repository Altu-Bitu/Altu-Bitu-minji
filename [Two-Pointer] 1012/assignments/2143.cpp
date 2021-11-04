//
// Created by Kang Minji on 2021-11-02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//어떤 배열의 가능한 부 배열의 합 모두 구하는 함수
vector<int> partSum(int n, vector<int> num) {
    vector<int> part_sum; // 부 배열 합 저장하는 배열
    for (int i = 0; i < n; i++) { // 배열의 길이만큼
        int sum = 0; // 각 단계마다 부배열의 합 초기화
        for (int j = i; j < n; j++) { // 부배열 구하기
            sum += num[j]; //i-j의 부 배열 합
            part_sum.push_back(sum); // 배열 합 저장하는 배열에 값 추가
        }
    }

    return part_sum; // 부 배열 합 반환
}

//T만드는 쌍의 개수 구하는 함수
long long cntMakeTarget(vector<int> &sum_a, vector<int> &sum_b, int left, int right, int target) {
    long long ans = 0; // T 만드는 쌍의 개수
    while (left < sum_a.size() && right >= 0) { // 포인터가 범위 내에 있는 경우(뒤집히지 않는 경우)
        int sum = sum_a[left] + sum_b[right]; // 두 부 배열의 합 구하기
        if (sum == target) { //두 부 배열 합이 T와 같은 경우
            long long cnt_a = 1, cnt_b = 1; // 각 배열의 값의 개수
            while (left + 1 < sum_a.size() && sum_a[left] == sum_a[left + 1]) { // A 배열에서 동일한 값 있는지 확인
                cnt_a++; // A 배열의 값 개수 증가
                left++; // 포인터 증가
            }
            while (right - 1 >= 0 && sum_b[right] == sum_b[right - 1]) { // B 배열에서 동일한 값 있는지 확인
                cnt_b++; // B 배열의 값 개수 증가
                right--; // 포인터 감소
            }
            left++; // 왼쪽 포인터 증가
            right--; // 오른쪽 포인터 감소
            ans += cnt_a * cnt_b; // A 배열에서 해당 값 개수 * B 배열에서 해당 값 개수 구해서 한꺼번에 더함
        } else if (sum < target) //T보다 작은 경우
            left++; // 왼쪽 포인터만 증가
        else if (sum > target) //T보다 큰 경우
            right--; // 오른쪽 포인터만 감소
    }

    return ans; // T 만드는 쌍의 개수 반환
}

/**
 * 1. 부 배열은 i-j까지의 연속된 부분 배열을 의미함
 * 2. 각 A, B배열에 대한 가능한 부 배열의 합을 모두 구함
 * 3. A배열의 부 배열 합 중 가장 작은 값과 B배열의 부 배열 합 중 가장 큰 값에서 포인터를 시작하여 T를 만들 수 있는지 검사
 * 4. 이때, 포인터를 차례로 움직이는 검사를 가능하게 하기 위해선, 부 배열 합들을 미리 오름차순 정렬해 놓아야 함
 * 5. A, B의 부 배열 합이 T를 만들 수 있다면, 현재 부 배열 합과 같은 값들을 한 번에 구한 후 곱해서 더해줌 (이렇게 해야 모든 경우 탐색 가능)
 * ex. A의 부 배열 합 리스트: 1 2 2 2 4 6
 *     B의 부 배열 합 리스트: 4 6 6
 *     만약 T = 8이라면 처음 2와 6에 걸렸을 때, 2의 개수(3개)를 한 번에 구하고 6의 개수(2개)를 한 번에 구한 후 곱해야 2와 6에 대한 모든 경우의 수(6) 구할 수 있음
 *     한 번에 구하지 않고, left + 1 을 하거나, right - 1을 할 경우 그 다음 6에 대한 경우를 고려하지 못함
 *
 * !주의! 각 부 배열 합이 최대 500,500개 있으므로 모든 쌍이 T를 만든다면 500,500 * 500,500이 되어서 정답은 long long 범위여야 함
 */

int main() {
    int t, n, m; // t : 부배열의 합, n : A 배열의 길이, m : B 배열의 길이

    //입력 + 각 A, B 배열의 부 배열 합 모두 구하기
    cin >> t >> n; // 부배열의 총합과 A 배열의 길이 입력
    vector<int> num_a(n, 0); // A 배열 초기화
    for (int i = 0; i < n; i++) // A 배열 길이만큼
        cin >> num_a[i]; // 입력받음
    vector<int> sum_a = partSum(n, num_a); // A에서 가능한 부배열의 합 모두 구하기

    cin >> m; // B 배열의 길이 입력
    vector<int> num_b(m, 0); // B 배열 초기화
    for (int i = 0; i < m; i++) // B 배열 길이만큼
        cin >> num_b[i]; // 입력받음
    vector<int> sum_b = partSum(m, num_b); // B에서 가능한 부배열의 합 모두 구하기

    //연산
    sort(sum_a.begin(), sum_a.end()); // A 순서대로 정렬
    sort(sum_b.begin(), sum_b.end()); // B 순서대로 정렬

    //연산 & 출력
    cout << cntMakeTarget(sum_a, sum_b, 0, sum_b.size() - 1, t);

    return 0;
}