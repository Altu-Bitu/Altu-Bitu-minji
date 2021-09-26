//
// Created by Kang Minji on 2021-09-26.
//

#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 64; // 체스판 칸 개수

// (row, col)에서 시작하는 8x8 체스판 만드는데 드는 최소 cnt return

int main(){
    int n, m;
    int ans = SIZE + 1; // 정답 초기화(체스판 칸 개수 + 1보다 작음)
    string s;

    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
}