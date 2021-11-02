//
// Created by Kang Minji on 2021-11-02.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 2; // 최대 V-1개의 간선을 지나게 됨

// 다익스트라
vector<int> dijkstra(int vertex, int start, vector<vector<ci>> &graph){
    vector<int> dist(vertex+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq; // first : 시작점으로부터의 거리, second :

    // 시작 위치 초기화
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) // 이미 확인했던 정점
            continue;
        // 연결된 모든 노드에 대해 탐색 진행
        for (int i=0; i<graph[node].size(); i++){
            int next_node=  graph[node][i].first;
            int next_weight = weight + graph[node][i].second; // weight 빠지면 Prim 되어버림!
            if (dist[next_node] > next_weight){
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;
}

int main(){
    int vertex, edge, k, u, v, w;

    // 입력
    cin >> vertex >> edge>>k;
    vector<vector<ci>> graph(vertex+1, vector<ci>(0)); // 인접 리스트
    while (edge--){
        cin >> u>>v>>w;
        //graph[u].push_back(make_pair(v, w));
        graph[u].emplace_back(v, w); // 방향 그래프(u -> v로 가는 가중치 w의 간선이 있다)
    }

    // 연산
    vector<int> ans = dijkstra(vertex, k, graph);

    // 출력
    for (int i=1; i<=vertex; i++){
        if (ans[i]==INF)
            cout << "INF";
        else
            cout << ans[i];
        cout << "\n";
    }
}