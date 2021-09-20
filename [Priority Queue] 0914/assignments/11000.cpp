//
// Created by Kang Minji on 2021-09-20.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<>> pq;
    int n;

    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }

    // 00. 강의 시작 순서대로 정렬(오름차순)
   sort(v.begin(), v.end());

    // 01. pq에 첫 번째 강의 종료 시간 넣기
    pq.push(v[0].second);

    for (int i=1; i<n; i++){
        // 1) 한 강의실에서 수업을 이어서 할 수 있는 경우 -> 값만 update
        if (pq.top() <= v[i].first){
            pq.pop();
            pq.push(v[i].second);
        }
        // 2) 시간이 겹치는 경우 -> 강의실 하나 늘리기
        else
            pq.push(v[i].second);
    }

    cout << pq.size();
}