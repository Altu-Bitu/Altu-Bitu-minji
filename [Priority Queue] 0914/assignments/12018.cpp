//
// Created by Kang Minji on 2021-09-20.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // pq : 과목별 신청할 수 있는 최소 마일리지를 "내림차순으로" 저장
    priority_queue<int, vector<int>, greater<>> pq;
    int n, m, p, l;
    cin >> n >> m;

    while (n--){
        cin >> p >> l;
        vector<int> v(p);

        // 과목별 마일리지 입력
        for (int i=0; i<p; i++)
            cin >> v[i];

        // 인원 미달 -> 최소 마일리지 1 부여
        if (p < l){
            pq.push(1);
            continue;
        }

        // 오름차순 정렬
        sort(v.begin(), v.end(), greater<>());
        pq.push(v[l-1]);
        // 내림차순 정렬 v[0] 안 되는 이유 : 등수에서 밀린 사람의 마일리지임!
    }

    int ans = 0;
    while (!pq.empty() && pq.top() <= m){
        m -= pq.top();
        pq.pop();
        ans++;
    }
    cout << ans;
}