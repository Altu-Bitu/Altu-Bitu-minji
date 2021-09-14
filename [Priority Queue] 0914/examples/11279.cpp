//
// Created by Kang Minji on 2021-09-14.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> heap_vec;

// empty
bool empty(){
    return heap_vec.size() == 1;
}

// push
void push(int num){
    int idx = heap_vec.size(); // 이번에 push할 데이터의 인덱스
    heap_vec.push_back(num);

    // root = 1에 도달하거나 더 이상 상위노드보다 값이 크지 않다면 반복문 탈출
    while(idx!=1 && heap_vec[idx] > heap_vec[idx/2]){
        swap(heap_vec[idx], heap_vec[idx/2]); // 하위노드와 상위노드의 값 바꿈
        idx /= 2; // 상위 노드로 이동
    }
}

// pop
int pop(){
    int item = heap_vec[1]; // 0이 아니라 1임
    swap(heap_vec[1], heap_vec[heap_vec.size()-1]); // 힙의 맨 마지막 값과 루트 값 바꿈
    heap_vec.pop_back(); // 아이템 제거

    int parent = 1, child = 2;
    // heap 갱신
    while(child<heap_vec.size()){ // 값이 존재할 때(루트 노드가 아닐 때)
        // 만약 오른쪽 하위노드가 존재하면 왼쪽 하위노드와 값을 비교하고, 상위노드와 비교할 하위노드 갱신
        if (child+1 < heap_vec.size() && heap_vec[child] < heap_vec[child+1])
            child++;
        // 나보다 큰 하위노드가 없다.
        if (heap_vec[parent] >= heap_vec[child])
            break;
        // 상위노드와 하위노드의 값 바꿈
       swap(heap_vec[parent], heap_vec[child]);
       parent = child;
       child = parent*2;
    }
    return item;
}

int main(){
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    priority_queue<int> pq;
    heap_vec.push_back(0); // 인덱스가 1부터 시작하도록

    cin >> n;
    while(n--){
        cin >> x;
        if(x==0){
            // pop
            if (pq.empty())
                cout << 0 << "\n";
            else
                cout << pq.pop() << "\n";
        }
        else{
            // push
            pq.push(x);
        }
    }
}
