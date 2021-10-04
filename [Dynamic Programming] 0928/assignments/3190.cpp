//
// Created by Kang Minji on 2021-10-04.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> body;
queue<pair<int, char>> moves;
queue<pair<int, int>> tail;

int n, k;
// 오른쪽, 아래, 왼쪽, 위쪽
int move_row[4] = {1, 0, -1, 0};
int move_col[4] = {0, -1, 0, 1};
int move_idx = 0; // 이동 방향 인덱스
int cur_row = 1;
int cur_col = 1;

bool dummy(int row, int col, int time){
    // 다음에 이동할 칸
    int x = row + move_row[move_idx];
    int y = col + move_col[move_idx];

    // 게임 끝나는 경우(벽에 부딪히거나 자기 몸과 부딪힘)
    if (x > n || y > n || x < 1 || y < 1 || body[x][y])
        return false;

    // 01. 다음 칸으로 이동
    tail.push({x, y});
    body[x][y] = 1;
    cur_row = x;
    cur_col = y;

    // 02-1) 사과가 있는 경우
    if (board[x][y] == 1)
        board[x][y] = 0;

        // 02-2) 사과가 없는 경우
    else {
        int tail_row = tail.front().first;
        int tail_col = tail.front().second;
        tail.pop();
        body[tail_row][tail_col] = 0;
    }

    // 03. 뱀 방향 바꾸는 경우
    if (moves.front().first == time){
        if (moves.front().second == 'L')
            move_idx = (move_idx + 3)%4;
        else
            move_idx = (move_idx + 1)%4;
        moves.pop();
    }
    return true;
}

int main(){
    int l, x;
    char c;

    // 입력
    cin >> n >> k;
    board.assign(n+1, vector<int>(n+1, 0));
    body.assign(n+1, vector<int>(n+1, 0));

    int row, col;
    for (int i=0; i<k; i++){
        cin >> row >> col;
        board[row][col] = 1; // 사과 위치 표시
    }

    cin >> l;
    for (int i=0; i<l; i++){
        cin >> x >> c;
        moves.push({x, c}); // 이동 방향 표시
    }

    // 연산
    int time = 0;
    body[1][1] = 1;
    tail.push({1, 1});
    while(true){
        time++;
        if (!dummy(cur_row, cur_col, time))
            break;
    }

    // 출력
    cout << time;
}