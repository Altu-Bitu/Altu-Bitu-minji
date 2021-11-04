//
// Created by Kang Minji on 2021-11-01.
//

// 참고 : https://jaimemin.tistory.com/623
// DFS 사용 가능(row, col 중 하나만 증가) : ㅡ, ㄴ, ㅁ, Z
// DFS 사용 불가(row, col 동시에 증가) : ㅜ

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> paper; // 종이에 쓰여 있는 수
vector<vector<bool>> visited; // 방문 표시용

//1) DFS 적용 가능한 테트로미노
int DFS(int n, int m, int x, int y, int cnt){
    if (cnt == 4) // 테트로미노 완성(칸 4개)
        return paper[x][y];

    // 이동하는 방향
    vector<int> px = {1, 0, -1, 0};
    vector<int> py = {0, -1, 0, 1};

    int sum = 0;
    for (int i=0; i<4; i++){
        // 다음에 이동할 좌표
        int nx = x + px[i];
        int ny = x + py[i];

        // 다음 좌표가 종이 내에 있다면(다음 탐색 진행)
        if (0<=ny && ny <n && 0<=nx && nx < m && !visited[nx][ny]){
            visited[nx][ny] = true;
            // 탐색 진행하면서 나온 값의 최대를 sum에 담는다!
            sum = max(sum, paper[x][y] + DFS(n, m, nx, ny, cnt+1));
            visited[nx][ny] = false;
        }
    }
    return sum;
}

// 2) DFS 적용 불가능한 ㅗ모양 테트로미노
int noDFS(int n, int m, int x, int y){
    int sum = 0;
    if (x>=1 && y>=1 && y < m-1) // 'ㅗ'모양
        sum = max(sum, paper[x][y-1]+paper[x][y] + paper[x-1][y] + paper[x][y+1]);
    if (x>=1 && x < n-1 && y < m-1) // 'ㅏ' 모양
        sum = max(sum, paper[x-1][y] + paper[x][y] + paper[x][y+1] + paper[x+1][y]);
    if (x>=0 && x < n-1 && y < m-1) // 'ㅜ' 모양
        sum = max(sum, paper[x][y-1] + paper[x][y] + paper[x+1][y] + paper[x][y+1]);
    if (x >=1 && x<n-1 && y>=1)
        sum = max(sum, paper[x-1][y] + paper[x][y] + paper[x][y-1] + paper[x+1][y]);
    return sum;
}

int main(){
    int n, m;
    int result = 0;

    // 입력
    cin >> n >> m;
    paper.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<bool>(m, false));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> paper[i][j];
        }
    }

    // 연산
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            visited[i][j] = true;
            // 1) DFS 적용 가능한 테트로미노 최댓값과 비교
            result = max(result, DFS(n, m, i, j, 1));
            // 2) DFS 적용 불가능한 ㅗ모양 테트로미노 최댓값과 비교
            result = max(result, noDFS(n, m, i, j));
            visited[i][j] = false; // 방문 표시 해제;
        }
    }

    // 출력
    cout << result << "\n";
}