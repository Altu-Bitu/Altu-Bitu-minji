//
// Created by Kang Minji on 2021-10-15.
//

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll; // long long 간단하게 쓰기

vector<ll> immigration; // 각 심사대에서 심사를 하는데 걸리는 시간

//심사를 받는데 걸리는 시간이 tot_time일 때, 심사를 받을 수 있는 사람의 수
ll cntPeople(ll tot_time) {
    ll cnt = 0; // 심사를 받을 수 있는 사람의 수
    for (int i = 0; i < immigration.size(); i++)
        cnt += (tot_time / immigration[i]); // 한 심사대 당 주어진 시간 내 심사할 수 있는 사람의 수를 cnt에 더해준다
    return cnt; // 모든 심사대에서 주어진 시간 내에 심사를 받을 수 있는 사람의 수 리턴
}

// 이분 탐색 수행하는 함수
ll lowerSearch(ll left, ll right, int target) {
    ll ans = 0; // 상근이와 친구들이 심사를 마치는데 걸리는 시간의 최솟값
    while (left <= right) {
        //심사를 받는데 걸리는 시간이 mid일 때, 몇 명의 친구들이 심사를 받을 수 있는가?
        ll mid = (left + right) / 2;
        ll entrance = cntPeople(mid); // 심사를 받는데 걸리는 시간이 mid일 때, 심사를 받을 수 있는 사람의 수

        if (entrance >= target) { // 심사를 받을 수 있는 사람의 수 >= 현재 인원 수 -> 시간 줄일 수 있음
            ans = mid; // 시간 최솟갑 갱신
            right = mid - 1; // 시간 범위를 줄인다(right 값 감소)
        } else if (entrance < target) // 심사를 받을 수 있는 사람의 수 < 현재 인원 수 -> 시간 늘려야 함
            left = mid + 1; // 시간 범위를 늘린다(left 값 증가)
    }
    return ans; // 최솟값 리턴
}

/**
 * 상근이와 친구들이 심사를 받는데 걸리는 시간의 최솟값
 * -> 시간이 t만큼 주어질 때, m명 이상의 친구들이 입국 심사를 받을 수 있는가?
 *
 * left : 모든 심사대의 심사 시간이 k이고, 심사대가 친구들의 수만큼 주어진다면 걸리는 시간은 k
 * right : 심사가 가장 오래 걸리는 심사대 k에서 모든 친구들이 한명씩 입국심사를 받는다면, 걸리는 시간은 k*m
 *
 * !주의! right k*m의 최댓값은 심사 시간의 최댓값 10^9와 m의 최댓값 10^9를 곱한 10^18이다.
 * 그러므로 long long 범위를 써야 함.
 */
int main() {
    int n, m; // n : 입국 심사대 개수, m : 상근이와 친구들 인원 수
    ll max_time = 0, min_time = 1e9; // 심사를 받는데 걸리는 최대, 최소 시간(right, left)

    //입력
    cin >> n >> m;
    immigration.assign(n, 0); // 심사 시간 벡터 초기화
    for (int i = 0; i < n; i++) {
        cin >> immigration[i]; // 각 심사대에서 심사를 하는 시간 입력
        max_time = max(max_time, immigration[i]); // right값 갱신
        min_time = min(min_time, immigration[i]); // left값 갱신
    }

    //연산 & 출력
    cout << lowerSearch(min_time, max_time * m, m); // 이분탐색 실행
}