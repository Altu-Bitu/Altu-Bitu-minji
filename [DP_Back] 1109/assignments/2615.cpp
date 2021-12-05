//
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