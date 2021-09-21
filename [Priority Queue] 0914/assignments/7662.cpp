//
// Created by Kang Minji on 2021-09-20.
//

// 실패
#include <iostream>
#include <queue>
using namespace std;

void print_heap( priority_queue<pair<int, int>> max_heap, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap){
    if (max_heap.empty() && min_heap.empty())
        cout << "EMPTY\n";
    else
        cout << max_heap.top().first << " " << min_heap.top().first << "\n";
}

void sync_heap(bool valid[], priority_queue<pair<int, int>> max_heap, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap){
    while(!max_heap.empty() && !valid[max_heap.top().second]){
        max_heap.pop();
    }
    while(!min_heap.empty() && !valid[min_heap.top().second]){
        min_heap.pop();
    }
}

int main(){
    // 값, valid 여부(0, 1)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap; // 오름차순
    priority_queue<pair<int, int>> max_heap; // 내림차순
    int t, k, n;
    char op;
    bool valid[1000001] = {true, };
    cin >> t;

    while(t--){
        cin >> k;
        for (int i=0; i<k; i++){
            cin >> op >> n;
            sync_heap(valid, max_heap, min_heap);
            // 01. 삽입 연산
            if (op == 'I'){
                min_heap.push({n, i});
                max_heap.push({n, i});
            }
                // 02. 삭제 연산
            else if (op == 'D'){
                if (n == 1){ // 최댓값 삭제
                    if (!max_heap.empty()){
                        valid[max_heap.top().second] = false;
                        max_heap.pop();
                    }
                }
                else if (n == -1) { // 최솟값 삭제
                    if (!min_heap.empty()){
                        valid[min_heap.top().second] = false;
                        min_heap.pop();
                    }
                }
            }
        }
        // 03. 최댓값 최솟값 출력
        print_heap(max_heap, min_heap);
    }
}