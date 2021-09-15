//
// Created by Kang Minji on 2021-09-15.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s; // 오른쪽 인형 바구니

    for (int col : moves){
        col -= 1; // 열(0부터 시작)
        for (int i=0; i<board.size(); i++){
            // 00. 인형 뽑기
            int doll_pos = board[i][col];
            board[i][col] = 0; // 인형 뺀 자리
            // 01. 칸에 아무것도 없는 경우 -> 무시
            if (doll_pos == 0)
                continue;
            // 02. 인형이 연속으로 있는 경우
            if (!s.empty() && s.top() == doll_pos){
                answer += 2;
                s.pop();
            }
            // 03. 인형이 존재하는 경우
            else
                s.push(doll_pos);
            // 04. 한 번 뽑았으면 중단하고 다음 열로 넘어간다(아래 칸까지 탐색 X)
            break;
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 0, 1, 0, 3},
                                 {0, 2, 5, 0, 1},
                                 {4, 2, 4, 4, 2},
                                 {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
    cout << solution(board, moves);
}