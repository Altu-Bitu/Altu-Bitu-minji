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
}