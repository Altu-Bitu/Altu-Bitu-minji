//
// Created by Kang Minji on 2021-11-02.
//

#include <iostream>
#include <vector>

using namespace std;

int ans, n, m;
vector<vector<int>> board;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

//board[row][col]을 가운데로 하는 +모양 만들기 -> 나중에 ㅜ 만들기 위해 제일 값이 작은 블록 뺀다
int horn(int row, int col) {
    // cnt : 블럭 개수, min_block : 해당 모양 중 제일 값이 작은 블록, sum : 해당 모양의 칸에 적혀있는 수들의 합
    int cnt = 0, min_block = 1001, sum = board[row][col];

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i]; // board[row][col]을 기준으로 모든 방향에 대해 탐색 진행
        int nc = col + dc[i]; // board[row][col]을 기준으로 모든 방향에 대해 탐색 진행

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) //범위를 벗어나면
            continue; // 무시한다
        min_block = min(min_block, board[nr][nc]); //가장자리 블럭 중 값이 가장 작은 블럭
        sum += board[nr][nc]; // sum
        cnt++; // 블럭 개수
    }

    if (cnt < 3) //가능한 가장자리가 최소 3개 이상이어야 함
        return 0;
    if (cnt == 3) //ㅗㅏㅜㅓ
        return sum;
    //+
    return sum - min_block;
}

//한붓 그리기가 가능한 블럭들 백트래킹 탐색
void backtracking(int row, int col, int cnt, int sum) {
    if (cnt == 4) { //기저조건 : 4개의 블럭을 탐색함
        ans = max(ans, sum); // 모든 경우의 수 중 최대인 것을 찾아서
        return; // 반환해준다.
    }

    // 모든 방향에 대해서(상, 하, 좌, 우) 탐색 진행
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i]; // row값 업데이트
        int nc = col + dc[i]; // col값 없데이트

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc]) //범위를 벗어나거나, 이미 방문했다면
            continue;
        int save = board[nr][nc]; // 백트래킹 진행 전에 저장
        board[nr][nc] = 0; // 일단 초기화
        backtracking(nr, nc, cnt + 1, sum + save); // 백트래킹 진행
        board[nr][nc] = save; // 진행 후 값 원상복귀
    }
}

/**
 * 1. 각 블럭을 백트래킹이 가능한 블럭과 불가능한 블럭으로 나누기
 *    -> 블럭을 한붓 그리기로 그릴 수 있으면 백트래킹이 가능 아니라면 불가능
 *    -> 보라색 블럭을 제외하면 모두 백트래킹 가능
 * 2. 보라색 블럭은 + 모양에서 가장자리를 하나 제거한 것과 같음
 *    -> 가운데 블럭을 중심으로 가장자리 블럭을 붙여보고 가능한 최댓값 구하기
 * 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신
 *
 * 해설 : https://myunji.tistory.com/297
 * *코드가 살짝 달라요(블로그 코드는 최적화 하기 전)
 */
int main() {
    //입력
    cin >> n >> m; // 종이의 세로 크기 n, 가로 크기 m
    board.assign(n, vector<int>(m, 0)); // paper m*n으로 초기화
    for (int i = 0; i < n; i++) { // 세로
        for (int j = 0; j < m; j++) // 가로
            cin >> board[i][j]; // 종이의 각 칸에 쓰여 있는 수 입력
    }

    //연산
    for (int i = 0; i < n; i++) { // 세로
        for (int j = 0; j < m; j++) { // 가로
            ans = max(ans, horn(i, j)); //보라색 블럭 처리
            int save = board[i][j]; // 일단 값 저장

            board[i][j] = 0; // 백트래킹하기 위해서 0으로 처리
            backtracking(i, j, 1, save); //나머지 모양 처리
            board[i][j] = save; // 다시 값 돌려놓기
        }
    }

    //출력
    cout << ans;
}