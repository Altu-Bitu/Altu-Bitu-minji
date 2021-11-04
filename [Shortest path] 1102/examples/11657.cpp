//
// Created by Kang Minji on 2021-11-02.
//


#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<int, int, int> ti;
const int INF = 1e6 * 5;

// 벨만-포드
vector<ll> bellmanFord(int n, int m, int start, vector<ti> &edges){
    // 오버플로우 X 언더플로우 O
    // 500 * 500
    vector<ll> dist(n+1, INF);

    dist[start] = 0; // 시작 위치 초기화

    for (int i=1; i<=n; i++){
        bool flag = true;
        for (int j=0; j<m; j++){
            // s->d로 가는 간선의 가중치가 w
            int s = get<0>(edges[j]);
            int d = get<1>(edges[j]);
            int w = get<2>(edges[j]);

            if (dist[s] == INF) // 아직 시작점에서 s로 가는 경로가 발견되지 않았으므로 갱신할 수 없음
                continue;

            ll next_weight = w + dist[s];
            if (dist[d] > next_weight){ // 더 짧은 경로로 갈 수 있다면
                if (i==n) // n번째 갱신이었다면 음의 사이클이 발생하는 것
                    return {INF+1};
                dist[d] = next_weight;
                flag = false;
            }
        }
        if (flag)

    }
    return dist;
}

int main(){
    int n, m, a, b, c;

    // 입력
    cin >> n >> m;
    vector<ti> edges(m); // 간선 정보를 저장할 벡터
    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    // 연산
    vector<ll> ans = bellmanFord(n, m, 1, edges);

    // 출력
    if (ans[0] == INF+1) { // 음의 사이클
        cout << -1;
        return 0;
    }
    for (int i=2; i)
}