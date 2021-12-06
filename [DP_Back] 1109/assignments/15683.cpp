//
// Created by KangMinji on 2021-11-16.
//

#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 65;
vector<vector<int>> board;

//cctv 범위 표시
void ray(int row, int col, int dir) {
    int dr[4] = {-1, 0, 1, 0}; // row : 상 우 하 좌(시계방향)
    int dc[4] = {0, 1, 0, -1}; // col : 상 우 하 좌

    while (row >= 0 && row < n && col >= 0 && col < m && board[row][col] != 6) { //dir 방향으로 뻗어나가며 cctv 표시
        if (board[row][col] == 0) //다른 cctv를 지우지 않기 위해 빈 공간일 때만 표시
            board[row][col] = 7; // visited 표시
        row += dr[dir]; // 해당 dir에 대한 row 증가
        col += dc[dir]; // 해당 dir에 대한 col 증가
    }
}

//cctv 방향 지정
void install(int cctv, int row, int col, int dir) {
    if (cctv >= 1) //1, 2, 3, 4, 5번 cctv
        ray(row, col, dir);
    if (cctv >= 2 && cctv != 3) //2, 4, 5번 cctv
        ray(row, col, (dir + 2) % 4);
    if (cctv >= 3) //3, 4, 5번 cctv
        ray(row, col, (dir + 1) % 4);
    if (cctv == 5) //5번 cctv
        ray(row, col, (dir + 3) % 4);
}

//사각지대 계산
int blindSpot() {
    int cnt = 0; // 사각지대의 크기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!board[i][j]) // 사각지대라면
                cnt++; // 사각지대 크기 증가
        }
    }
    return cnt; // 크기 반환(정답)
}

void backtracking(int idx) {
    if (idx == n * m) { //기저 조건 : 사무실의 모든 위치 확인
        ans = min(ans, blindSpot()); //사각지대 계산 후 최솟값 갱신
        return; // 탐색 종료
    }

    int row = idx / m; // 현재 row 계산
    int col = idx % m; // 현재 col 계산
    int cur = board[row][col]; // 현재 위치
    if (cur == 0 || cur == 6 || cur == 7) //cctv가 없는 곳
        return backtracking(idx + 1); // 다음 탐색 위치(인덱스)로 넘어감

    vector<vector<int>> save = board; //unvisited 처리용 board 상태 저장
    for (int i = 0; i < 4; i++) { //4개의 방향에 대해 cctv 설치
        install(cur, row, col, i); // visit 처리 및 방향 탐색
        backtracking(idx + 1); // 재귀 호출
        board = save; // unvisited 처리

        //2번 cctv의 방향 종류는 2개, 5번 cctv의 방향 종류는 1개
        if ((cur == 2 && i == 1) || (cur == 5 && i == 0))
            break;
    }
}

/**
 * cctv가 설치될 수 있는 모든 경우를 고려하는 완전탐색 문제
 *
 * 1. 각 cctv에 대해 가능한 모든 방향을 고려하여 설치
 *    1, 3, 4번 cctv : 4방향
 *    2번 cctv : 2방향
 *    5번 cctv : 1방향
 * 2. install 함수에서 각 cctv의 빛이 뻗어나갈 방향을 잡음
 * 3. ray 함수에서 cctv의 감시 가능 범위 표시
 * 4. 모든 위치를 확인했으면 blindSpot 함수를 통해 사각지대 계산
 *
 * 풀이 : https://myunji.tistory.com/411
 * 해당 코드는 위 링크의 코드를 리팩토링한 코드입니다.
 * 말로는 풀이를 설명하기 어려우니 링크를 꼭 확인해주세요!
 */
int main() {
    //입력
    cin >> n >> m; // 사무실의 세로 크기, 가로 크기
    board.assign(n, vector<int>(m)); // 사무실 상태 초기화
    for (int i = 0; i < n; i++) { // row
        for (int j = 0; j < m; j++) // col
            cin >> board[i][j]; // 사무실 상태 입력
    }

    //연산
    backtracking(0);

    //출력
    cout << ans;
}