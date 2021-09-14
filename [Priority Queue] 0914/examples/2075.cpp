//
// Created by Kang Minji on 2021-09-14.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * 우선순위 큐(최소 힙)에는 가장 큰 수부터 N번째 큰 수까지 총 N개의 숫자가 들어있음
 * 가장 큰 수부터 N번째 큰 수까지를 최소 합에 넣었기 떄문에 root에 있는 값은 N번째 큰 수가 된다.
 * */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, input;
    // 원래 greater는 가장 큰 수부터
    // pq에서의 greater : 가장 작은 수부터(정렬이랑 조건 반대)
    // compare가 true를 반환해야 swap된다!(sort와 반대)
    priority_queue<int, vector<int>, greater<>> pq; // 최소 힙

    cin >> n;
    int size = n*n;
    while(size--){
        cin >> input;

        if (pq.size() < n)
            pq.push(input);
        else if (pq.top() < input){
            pq.pop();
            pq.push(input);
        }
    }

    // 출력
    cout << pq.top();

}