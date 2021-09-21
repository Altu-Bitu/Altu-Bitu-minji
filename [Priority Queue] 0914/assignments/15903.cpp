//
// Created by Kang Minji on 2021-09-16.
//

/*
 * 우선순위 큐는 내림차순으로 정렬되어 있음.
 * 문제에서는 오름차순을 요하므로 바꿔줘야 함
 * */

#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<long long, vector<long long>, greater<>> pq;
    int n, m, card;
    long long ans = 0;
    cin >> n >> m;

    while (n--){
        cin >> card;
        pq.push(card);
    }

    while (m--){
        long long tmp1 = pq.top();
        pq.pop();
        long long tmp2 = pq.top();
        pq.pop();
        pq.push(tmp1 + tmp2);
        pq.push(tmp1 + tmp2);
    }

    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}