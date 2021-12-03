//
// Created by KangMinji on 2021-11-14.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 2; //최대 N*N 칸을 지나게 됨

int dijkstra(int n, vector<vector<int>> &board) {
    int dr[4] = {-1, 1, 0, 0}; // row 경우의 수(좌 우 하 상)
    int dc[4] = {0, 0, -1, 1}; // col 경우의 수(좌 우 하 상)

    int ans = 0; // 잃는 루피의 수
    vector<vector<int>> dist(n, vector<int>(n, INF)); // 거리 저장
    priority_queue<pair<int, ci>, vector<pair<int, ci>>, greater<>> pq; // 우선순위 큐

    //시작 위치 초기화
    dist[0][0] = board[0][0]; // 시작 위치를 [0][0]으로 초기화
    pq.push(make_pair(dist[0][0], make_pair(0, 0))); // 큐에 삽입

    while (!pq.empty()) {
        int weight = pq.top().first; // edge 저장
        int row = pq.top().second.first; // row값
        int col = pq.top().second.second; // col값
        pq.pop(); // 큐에서 제거

        if (row == n - 1 && col == n - 1) { //제일 오른쪽 아래 칸 도착
            ans = weight; // 잃는 루피의 수 갱신
            break; // 탈출
        }
        if(weight > dist[row][col]) //이미 확인했던 좌표
            continue; // 패스
        for (int i = 0; i < 4; i++) { // 상, 하, 좌, 우 경우의 수만큼 따지기
            int nr = row + dr[i]; // 다음에 이동할 row 좌표
            int nc = col + dc[i]; // 다음에 이동할 col 좌표
            if ((nr < 0) || (nr >= n) || (nc < 0) || (nc >= n)) //범위를 벗어난다면
                continue; // 패스

            int next_weight = weight + board[nr][nc]; //시작점으로부터 연결된 좌표까지의 거리
            if (dist[nr][nc] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[nr][nc] = next_weight; // 짧은 경로로 갱신
                pq.push({next_weight, {nr, nc}}); // 큐에 삽입
            }
        }
    }
    return ans; // 잃는 루피의 수 리턴
}

/**
 * 상하좌우로 이동 가능 -> 연결됐다는 것
 * 시작 지점이 (0, 0)인 다익스트라
 */
int main() {
    int n, num = 1; // 동굴의 크기, 정답 형식용 num

    while (true) {
        //입력
        cin >> n; // 동굴의 크기 입력
        if (n == 0) // 전체 입력 종료
            break;

        vector<vector<int>> board(n, vector<int>(n, 0)); // 동굴의 각 칸(보드)
        for (int i = 0; i < n; i++) { // 도둑루피가 있는 row
            for (int j = 0; j < n; j++) // 도둑루피가 있는 col
                cin >> board[i][j]; // 각 칸에 있는 도둑루피의 크기
        }

        //연산 & 출력
        cout << "Problem " << num++ << ": " << dijkstra(n, board) << '\n';
    }
}