//
// Created by Kang Minji on 2021-11-01.
//
// 참고 : https://jdselectron.tistory.com/53

#include <iostream>
#include <vector>
#define SIZE 50
using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> visited;

// 한 칸만 움직이는 경우 4개 / 상하 둘 다 움직이는 경우 4개
int dh[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dw[8] = {0, -1, 0, 1, 1, -1, -1, 1};

void DFS(int h, int w){
    visited[h][w] = true; // 방문 체크

    // 모든 방향을 탐색해서
    for (int i=0; i<8; i++){
        int nh = dh[i] + h;
        int nw = dw[i] + w;
        // 새로운 섬의 좌표가 지도 안에 있고,
        if (0 <= nh && nh<SIZE && 0<=nw && nw<SIZE){
            // 해당 섬이 실제로 존재하며 방문하지 않았을 때
            if (graph[nh][nw] && !visited[nh][nw]) {
                DFS(nh, nw);
            }
        }
    }
}

int main(){
    int w, h;

    // 입력
    while(true) {
        cin >> w >> h;
        if (w == 0 && h == 0) // 입력의 마지막 줄
            break;

        // 초기화
        graph.assign(SIZE, vector<int>(SIZE, 0));
        visited.assign(SIZE, vector<bool>(SIZE, false));

        // 섬의 위치 입력(graph)
        for (int i = 0; i < h; i++)
            for (int j=0; j < w; j++)
                cin >> graph[i][j];

        // 탐색
        int cnt = 0;
        for (int i=0; i<h; i++){
            for (int j=0; j<w; j++){
                if (graph[i][j] && !visited[i][j]){ // 섬 존재하고 아직 방문하지 않았을 때
                    cnt++; // 섬의 갯수 증가
                    DFS(i, j);
                }
            }
        }
        cout << cnt << "\n";
    }
}