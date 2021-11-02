//
// Created by Kang Minji on 2021-11-02.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 3 * 1e9 + 1; // 세 용액의 최댓값

ll min_diff = INF; // 특성값의 차이

//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<ll, ll> liquid(vector<ll> &arr, ll fixed, int left, int right) {
    pair<ll, ll> ans; // 특성값이 0에 가장 가까운 용액(한 개는 고정, 나머지 2개 찾기)
    ans = make_pair(INF, INF); // 최댓값으로 초기화시킴

    //left는 항상 right의 왼쪽에 있어야 함
    while (left < right) {
        ll mix = fixed + arr[left] + arr[right]; //세 용액을 혼합
        if (mix == 0) //그 값이 0이라면 이보다 더 0에 가까워질 수는 없기 때문에 바로 리턴
            return make_pair(arr[left], arr[right]); // 해당 튜플 값 리턴
        if (abs(mix) < min_diff) { //0에 가까운 값을 갱신할 수 있는지 확인
            min_diff = abs(mix); // 절댓값 구하기
            ans = make_pair(arr[left], arr[right]); // 튜플 값 갱신
        }
        if (mix > 0) //0보다 크면 더 작은 값을 만들어야 함
            right--; // 오른쪽 포인터 감소
        else if (mix < 0) //0보다 작으면 더 큰 값을 만들어야 함
            left++; // 왼쪽 포인터 증가
    }
    return ans; // 특성값이 0에 가장 가까운 용액 쌍 리턴
}

/**
 * 2470번 : 두 용액 섞기
 * 2473번 : 세 용액 섞기
 *
 * 1. 하나의 용액을 반드시 사용한다고 가정
 * 2. 용액 하나 고정
 * 3. 해당 용액 이후의 범위에 대해 투 포인터 알고리즘 적용
 *
 * pair : 2개의 값 저장
 * tuple : 3개의 값 저장
 *
 * !주의! 세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억이고, int를 넘어감!
 */
int main() {
    int n; // 전체 용액의 수

    //입력
    cin >> n; // 전체 용액의 수 입력
    vector<ll> arr(n, 0); // 용액의 특성값 담는 배열 초기화
    for (int i = 0; i < n; i++) // 용액의 수 만큼
        cin >> arr[i]; // 용액의 특성값 입력

    //연산
    sort(arr.begin(), arr.end()); // 용액의 특성값 순서대로 정렬
    tuple<ll, ll, ll> ans; // 특성값이 0에 가장 가까운 용액을 만들어내는 세 용액을 담는 튜플
    for (int i = 0; i < n - 2; i++) { // 3개 구하기
        pair<ll, ll> p = liquid(arr, arr[i], i + 1, n - 1); //arr[i] 용액은 고정
        if ((p.first != INF) && (p.second != INF)) //최솟값이 갱신된 경우
            ans = make_tuple(arr[i], p.first, p.second); // 튜플에 추가
    }

    //출력
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
}