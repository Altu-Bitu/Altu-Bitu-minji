//
// Created by KangMinji on 2021-11-16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
//상, 좌, 좌상향
int dr[3] = {-1, 0, -1};
int dc[3] = {0, -1, -1};

//역추적
string back(string str1, vector<vector<int>> &path) {
    string result = ""; // LCS 담을 문자열
    int r = n, c = m; // 문자열 1, 2의 길이를 담음
    while (path[r][c] != -1) { // 저장한 방향을 따라서 탐색 진행
        int d = path[r][c]; // 탐색할 방향
        if (d == 2) //좌상향에서 가져온 경우 -> str1[r - 1] == str2[c - 1]
            result += str1[r - 1]; // str1이나 2나 길이 똑같으므로 1에서 가져옴
        r += dr[d]; //역추적
        c += dc[d]; //역추적
    }
    reverse(result.begin(), result.end()); // 역추적했으니까 reverse
    return result; // 만들어진 LCS 문자열 리턴
}

//LCS 길이 구하는 함수
int lcs(string str1, string str2, vector<vector<int>> &path) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) { // 문자열 1의 길이만큼 비교
        for (int j = 1; j <= m; j++) { // 문자열 2의 길이만큼 비교
            // 1) 두 문자가 서로 다른 경우
            if (str1[i - 1] != str2[j - 1]) { //두 문자가 서로 다르면
                dp[i][j] = dp[i - 1][j]; //우선 위쪽 값 가져온 것으로 저장
                path[i][j] = 0; //경로(방향) 저장
                if (dp[i][j] < dp[i][j - 1]) { //왼쪽이 더 크다면
                    dp[i][j] = dp[i][j - 1]; // 왼쪽 값 가져옴
                    path[i][j] = 1; //경로(방향) 저장
                }
            }
            // 2) 두 문자가 서로 같은 경우
            else if (str1[i - 1] == str2[j - 1]) { //두 문자가 서로 같다면
                dp[i][j] = dp[i - 1][j - 1] + 1; // 좌상향 대각선의 값 + 1
                path[i][j] = 2; //경로(방향) 저장
            }
        }
    }
    return dp[n][m]; //LCS 길이 리턴
}

/**
 * 기본 문제: LCS (해당 풀이는 "08. 동적계획법.pdf" 참고)
 * 1) 문자가 서로 다른 곳 : 그 전의 길이 최댓값 그대로
 * 그 전이란 ? 위쪽 / 왼쪽 중 큰 쪽
 * 2) 문자가 서로 같은 곳 : 해당 문자들이 포함되기 전의 길이 +1
 * 그 전이란? 좌상향 대각선
 *
 * [역추적]
 * - 위쪽, 왼쪽, 좌상향 중 어느 방향에서 왔는지 경로를 저장한 후, 역추적하는 문제
 * - 경로 저장은 dp배열이 갱신될 때 함
 *
 * 해당 풀이는 인덱스를 편하게 관리하기 위해 dp와 path 배열을 (1, 1)부터 시작
 */

int main() {
    string str1, str2; // 알파벳 대문자로 이루어진 두 문자열

    //입력
    cin >> str1 >> str2;
    n = str1.length(); // 문자열 1의 길이
    m = str2.length(); // 문자열 2의 길이
    vector<vector<int>> path(n + 1, vector<int>(m + 1, -1)); //그 전 방향 저장

    //연산
    int ans = lcs(str1, str2, path); //lcs
    string result = back(str1, path); //역추적

    //출력
    cout << ans << '\n' << result << '\n';
    return 0;
}