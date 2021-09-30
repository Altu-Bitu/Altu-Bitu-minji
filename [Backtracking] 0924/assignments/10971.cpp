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

// start : 시작 도시, end : 도착 도시
// cnt : 방문한 도시의 수, cost : 누적 비용
void backtracking(int start, int end, int cnt, int cost){
    // 모든 도시를 다 방문했는가? + 처음 도시로 돌아갈 수 있는가?
    if (cnt == n-1 && weight[start][end] != 0){
        cost += weight[start][end]; // 처음 도시로 돌아가는 비용
        min_cost = min(min_cost, cost);
        return;
    }
    // 나머지 도시를 하나씩 방문
    for (int i=0; i<n; i++){
        // 아직 방문하지 않은 도시 + 현재 도시에서 갈 수 있는 도시인 경우
        if (!check[i] && weight[start][i] != 0){
            check[i] = true; // 방문 체크
            cost += weight[start][i];
            // 최솟값보다 작을 때만 탐색 진행한다!
            if (cost < min_cost)
                backtracking(i, end, cnt+1, cost); // [1, 2]였으면 [2, *]로 보내준다
            check[i] = false;
            cost -= weight[start][i];
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
    // 시작 도시 별로 탐색하되, 시작과 끝이 모두 하나의 도시로!
    for (int i=0; i<n; i++){
        check[i] = true;
        backtracking(i, i, 0, 0);
        check[i] = false;
    }

    cout << min_cost;
}