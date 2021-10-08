//
// Created by Kang Minji on 2021-09-26.
//

#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 64; // 체스판 칸 개수

// (row, col)에서 시작하는 8x8 체스판 만드는데 드는 최소 cnt return
// B로 시작하는 체스판을 기준으로 계산한 후, W로 시작하는 체스판 최솟값 수는 64에서 빼서 계산
int chessChange(int row, int col, vector<vector<char>> &board){
    int b_cnt = 0; // B로 시작하는 체스판 만들기 위한 cnt

    // i+j의 합이 짝수이면 B, 홀수이면 W
    for (int i=0; i<8; i++){ // 행 변화값
        for (int j=0; j<8; j++){ // 열 변화값
            // 행 변화값 + 열 변화값이 짝수면 시작색(B)과 동일해야 함 -> 동일하지 않다면 카운트
            if ((i+j)%2 == 0 && board[row+i][col+j] != 'B')
                b_cnt++;
            // 행 변화값 + 열 변화값이 홀수면 시작색과 반대색(W)이어야 함 -> W가 아니라면 카운트
            else if ((i+j)%2 == 1 && board[row+i][col+j] != 'W')
                b_cnt++;
        }
    }

    // 최솟값 리턴
    if (b_cnt > SIZE / 2)
        return SIZE - b_cnt; // W로 시작하는 게 더 적다
    return b_cnt;
}


int main(){
    int n, m;
    int ans = SIZE + 1; // 정답 초기화(체스판 칸 개수 + 1보다 작음)
    string s;

    // 입력
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m)); // 행 : n, 열 : m
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> board[i][j];

    // 연산
    for (int i=0; i<=n-8; i++){
        for (int j=0; j<=m-8; j++){
            int cnt = chessChange(i, j, board); // 시작 인덱스가 (i, j)인 체스판 만드는 최솟값값
            ans = min(ans, cnt); // 최솟값 갱신
        }
    }

    // 출력
    cout << ans << "\n";
}