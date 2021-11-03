//
// Created by Kang Minji on 2021-11-02.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 5;

//특정 응시자에 대해 거리두기가 지켜지는지 확인
bool bfs(vector<string> &place, int row, int col) {
    int dr[4] = {-1, 1, 0, 0}; // 방향을 담은 배열
    int dc[4] = {0, 0, -1, 1}; // 방향을 담은 배열

    vector<vector<int>> dist(SIZE, vector<int>(SIZE, 0)); //방문 여부, 각 정점까지의 맨허튼 거리
    queue<pair<int, int>> q; // 큐

    dist[row][col] = 1; //초기값이 0이기 때문에 1로 초기화
    q.push(make_pair(row, col)); // 큐에 해당 응시자의 위치 넣기

    while (!q.empty()) { // BFS 조건
        int cr = q.front().first; // 응시자 좌표(행)
        int cc = q.front().second; // 응시자 좌표(열)
        q.pop(); // 큐에서 응시자 좌표 제거

        if (dist[cr][cc] == 3) //맨허튼 거리 2이하까지만 탐색
            continue; // 원하는 조건이 아니므로 넘어감

        for (int i = 0; i < 4; i++) { // 상, 하, 좌, 우 탐색
            int nr = cr + dr[i]; // 응시자 주변 좌표(가로)
            int nc = cc + dc[i]; // 응시자 주변 좌표(세로)

            //범위를 벗어나거나, 방문했거나, 파티션이 있음
            if (nr < 0 || nr >= SIZE || nc < 0 || nc >= SIZE || dist[nr][nc] || place[nr][nc] == 'X')
                continue; // 거리두기 지킴
            if (place[nr][nc] == 'P') //응시자가 있으면 거리두기 지키지 못함
                return false; // 바로 리턴
            dist[nr][nc] = dist[cr][cc] + 1; // 해당 정점까지의 맨허튼 거리 증가
            q.push(make_pair(nr, nc)); // 다음에 탐색할 좌표 넣기
        }
    }
    return true; //거리두기 지킴
}

//특정 대기실에 대해 거리두기가 지켜지는지 확인
bool socialDistance(vector<string> &place) {
    for (int i = 0; i < SIZE; i++) { // 대기실 행
        for (int j = 0; j < SIZE; j++) { // 대기실 열
            //응시자가 있다면, 거리두기 확인
            if (place[i][j] == 'P' && !bfs(place, i, j)) // 해당 위치에 사람이 있고, 주변에 거리두기가 안 되어 있다면
                return false; // false 리턴
        }
    }
    return true; // 거리두기 잘 되어있으면 true 리턴
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer; // 거리두기 여부를 담을 배열
    for (int i = 0; i < SIZE; i++) // 각 대기실 별로
        answer.push_back(socialDistance(places[i])); // 거리두기 여부 구해서 넣음
    return answer; // 배열 리턴
}

/**
 * 맨허튼 거리가 2이하 == BFS 또는 DFS 했을 때의 거리가 2이하
 *
 * 각 대기실의 모든 응시자에 대해 거리두기를 지키고 있는지 확인
 * 5x5 크기의 대기실 5개이기 때문에 모든 응시자에 대해 bfs 또는 dfs를 수행해도 시간 초과 발생하지 않음
 */
int main() {
    // 대기실의 응시자/빈 테이블/파티션 상태
    vector<vector<string>> places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                                     {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                                     {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                                     {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                                     {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    vector<int> ans = solution(places); // 거리두기 여부
    for (int i = 0; i < SIZE; i++) // 각 대기실 별로
        cout << ans[i] << ' '; // 거리두기 여부 출력
}