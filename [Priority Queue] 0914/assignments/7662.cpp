//
// Created by Kang Minji on 2021-09-20.
//

// 성공
// 실패한 이유 : non-const value 불러오는 데 & 쓰지 않음.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<bool> is_valid;

// 최대 힙에서 top 데이터가 is_valid할 때까지 pop
void deleteMax(priority_queue<pair<int, int>> &heap){
    while(!heap.empty() && !is_valid[heap.top().second]){
        heap.pop();
    }
}

// 최소 힙에서 top 데이터가 is_valid할 때까지 pop
void deleteMin(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> &heap){
    while(!heap.empty() && !is_valid[heap.top().second]){
        heap.pop();
    }
}

int main(){
    int t, k, n;
    char op;
    cin >> t;

    while(t--){
        // 값, valid 여부(0, 1)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap; // 최소 힙
        priority_queue<pair<int, int>> max_heap; // 최대 힙

        cin >> k;
        int idx = 0; // 연산으로 입력된 숫자의 인덱스
        while(k--){
            // 입력
            cin >> op >> n;

            switch (op){
                // 01. 삽입 연산
                case 'I': // 두 힙 모두에 값을 넣은 후, valid에도 추가
                    min_heap.push({n, idx});
                    max_heap.push({n, idx});
                    is_valid.push_back(true);
                    idx++;
                    break;
                case 'D':
                // 02. 삭제 연산
                    if (n == 1){ // 최댓값 삭제
                        deleteMax(max_heap); // D 연산 전처리
                        if (!max_heap.empty()) { //D연산
                            is_valid[max_heap.top().second] = false;
                            max_heap.pop();
                        }
                    }
                    if (n == -1) { // 최솟값 삭제
                        deleteMin(min_heap); // D 연산 전처리
                        if (!min_heap.empty()) { //D연산
                            is_valid[min_heap.top().second] = false;
                            min_heap.pop();
                        }
                    }
                    break;
            }
        }
        // 각 힙의 top이 valid하도록 처리
        deleteMax(max_heap);
        deleteMin(min_heap);

        // 출력
        if (max_heap.empty())
            cout << "EMPTY\n";
        else
            cout << max_heap.top().first << " " << min_heap.top().first << "\n";
        is_valid.clear(); // 새로운 테스트 케이스 전 벡터 초기화
    }
}