//
// Created by KangMinji on 2021-11-16.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //최대 n-1개의 간선을 지나게 됨

void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &table) {
    for (int k = 1; k <= n; k++) { // 중간에 거치는 노드
        for (int i = 1; i <= n; i++) { // 모든 i, j 확인
            for (int j = 1; j <= n; j++) {
                int new_dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                if (new_dist < graph[i][j]) { //i->k->j가 i->j보다 빠른 경로라면
                    graph[i][j] = new_dist; // i->j 경로 갱신
                    table[i][j] = table[i][k]; // i->j로 가기 위해 제일 먼저 거쳐야 하는 정점 = i->k로 가기 위해 제일 먼저 거쳐야 하는 정점
                }
            }
        }
    }
}

/**
 * graph : 플로이드-워셜 결과 행렬 그래프
 * table : 경로표. table[i][j] = i->j로 가기 위해 제일 먼저 거쳐야 하는 정점
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 i->k의 중간 경로(table[i][k])로 갱신
 *    k로 갱신하는게 아니라 table[i][k]로 갱신하는 이유는?
 *    만약 i->k의 경로가 i->t->k라면 최종 경로는 i->t->k->j
 *    바로 k로 갱신하면 t를 놓칠 수 있기 때문에 table[i][k]로 갱신
 *    line 16을 table[i][j] = k로 바꾸면 결과가 어떻게 되는지 확인해보세요
 */
int main() {
    // n : 집하장의 개수, m : 집하장간 경로의 개수
    // s : 시작 집하장 번호, d : 도착 집하장 번호, c : 오가는데 필요한 시간
    int n, m, s, d, c;

    //입력
    cin >> n >> m; // node, edge 입력
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF)); // 플로이드워셜 결과 그래프
    vector<vector<int>> table(n+1, vector<int>(n+1, 0)); // 경로표
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0; // 대각행렬 0으로 초기화

    while (m--) { //무방향 그래프
        cin >> s >> d >> c; // 시작, 도착 번호와 시간 입력
        //간선 정보
        graph[s][d] = graph[d][s] = c; // 시간 정보 입력(s->d / d->s) -> weight

        //경로 정보
        table[s][d] = d; // s->d로 가기 위해 제일 먼저 거쳐야 하는 정점
        table[d][s] = s; // d->s로 가기 위해 제일 먼저 거쳐야 하는 정점
    }

    //연산
    floydWarshall(n, graph, table);

    //출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) // 대각선이면
                cout << "- ";
            else
                cout << table[i][j] << ' '; // 경로표 출력
        }
        cout << '\n';
    }
}