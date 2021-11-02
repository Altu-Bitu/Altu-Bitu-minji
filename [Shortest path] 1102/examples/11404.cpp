//
// Created by Kang Minji on 2021-11-02.
//

#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e7; // 최대 n-1의 간선을 지나게 됨

// 플로이드-워셜(음수여도 사용 가능)
void floydWarshall(int n, vector<vector<int>> &graph){
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                int dist = graph[i][k] + graph[k][j]; // 중간에 k를 거쳐서 i에서 j로
                graph[i][j] = min(graph[i][j], dist); // i->j와 i->k->j 중 더 짧은 경로
            }
        }
    }
}

int main(){
    int n, m, a, b, c;

    // 입력
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    for (int i=1; i<=n; i++) // 자기 자신과의 거리를 초기화
        graph[i][i] = 0;

    while(m--){
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c); // 중복 간선이 들어올 수 있으므로 최솟값 사용
    }

    // 연산
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}