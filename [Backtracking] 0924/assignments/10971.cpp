//
// Created by Kang Minji on 2021-09-30.
//

#include <iostream>
using namespace std;
const int SIZE = 10;

int n, start;
int weight[SIZE][SIZE]; // 최소 비용 행렬
bool check[SIZE]; // 방문한 도시 체크
int min_cost = 2147483647;

// city : 현재 있는 도시
void backtracking(int city, int cnt, int cost){ // cnt : 방문한 도시 수, cost : 누적 비용
    if (cnt == n && start == city){ // 다 방문하고 처음 도시로 돌아온 경우
        min_cost = min(min_cost, cost);
        return;
    }
    for (int i=0; i<n; i++){
        if (weight[city][i] == 0) // 연결되지 않은 경우
            continue;
        // 방문하지 않은 경우
        if (!check[i]){
            check[i] = true; // 방문 체크
            cost += weight[city][i];
            // 최솟값보다 작을 때만 탐색 진행한다!
            if (cost < min_cost)
                backtracking(i, cnt+1, cost); // [1, 2]였으면 [2, *]로 보내준다
            check[i] = false;
            cost -= weight[city][i];
        }
    }
}

int main(){

    // 입력
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> weight[i][j];

    // 연산 + 출력
    for (int i=0; i<n; i++){
        start = i;
        backtracking(i, 0, 0);
    }

    cout << min_cost;
}