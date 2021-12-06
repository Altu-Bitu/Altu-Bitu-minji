//
// Created by KangMinji on 2021-11-16.
//

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>> &board) {
    return r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == stone;
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>> &board) {
    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] = {0, 1, 1, -1}; // row
    int dc[4] = {1, 0, 1, 1}; // col

    //(r, c) 이전에 위치한 이어지는 돌이 있나?
    bool is_six = promising(r - dr[d], c - dc[d], stone, board);

    int cnt = 0; // 연속된 돌의 개수
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
        cnt++; // 목 증가
        r += dr[d]; // 해당 방향으로 row 증가
        c += dc[d]; // 해당 방향으로 col 증가
    }
    return cnt == 5 && !is_six; // 오목 o 육목 x 여부 반환
}

bool isEnd(int r, int c, vector<vector<int>> &board) {
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board)) // 오목이 성립되었을 경우
            return true; // 승부가 결정된 경우 -> true 반환
    }
    return false; // 오목이 아닐 경우
}

/**
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. 육목이상이 되는 경우 : (r, c) 왼쪽에 같은 돌이 있는 경우
 */
int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); // 보드판

    //입력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cin >> board[i][j]; // 보드의 각 자리 입력
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j]) //돌이 없음
                continue; // 넘어감
            if (isEnd(i, j, board)) { //누군가 이겼나?(승부가 결정되었을 경우)
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1; // 이긴 돌의 색깔과 해당 돌의 가로, 세로 출력
                return 0; // 종료조건!!! 이걸 안 넣어주면 계속 탐색 진행함
            }
        }
    }
    cout << 0;

// Created by KangMinji on 2021-11-15.
//
// https://keoroo.tistory.com/33
// https://skygood95.tistory.com/19

#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 19;

// 탐색 방향 : 우, 우상향, 우하향, 하
int dx[4] = {1, 1, 1, 0};
int dy[4] = {0, 1, -1, -1};
int final_color = -1, final_x = -1, final_y = -1;

void omok(vector<vector<int>> &board, int x, int y){
    int nx, ny;
    // 1) 4가지 방향으로 탐색
    for (int i=0; i<4; i++){

        nx = x + dx[i];
        ny = y + dy[i];

        // 2) 각 방향별로 연속 확인
        for (int j=0; j<5; j++){;
            if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE || board[x][y] != board[nx][ny]){ // 범위에서 벗어나거나 색깔 다른 경우
                break;
            }
            // 해당 방향으로 전진
            nx += dx[i];
            nx += dy[i];
        }

        // 3) 연속 갯수 확인
        if (final_x > nx){
            final_color = board[x][y];
            final_x = nx;
            final_y = ny;
        }
    }
}

/*
 * 검은색 1, 흰색 2, 말 없는 경우 0
 * 가로, 세로, 대각선 방향 중 하나라도 연속으로 다섯 알 놓인 경우
 * 여섯 알 이상이 연속적으로 놓인 경우에는 이긴 것이 아님
 */
int main(){
    int ans = 0;
    vector<vector<int>> board(SIZE, vector<int>(SIZE));

    // 입력
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++) {
            cin >> board[i][j];
            // 연산
            if (board[i][j] == 0) // 돌이 없는 경우는 연산 X
                continue;
            omok(board, i, j);
        }
    }

    // 출력
    cout << final_color << "\n";
    cout << final_x << ' ' << final_y << "\n";
}