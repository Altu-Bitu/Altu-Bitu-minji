//
// Created by Kang Minji on 2021-09-28.
//

#include <iostream>
#include <vector>
using namespace std;

int maxScore(int n, vector<int> &score){
    vector<int> dp(n+1, 0); // 각 계단까지의 최댓값 저장

    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    for (int i=3; i<=n; i++)
        // 2칸 전에서 온 경우(2칸 이동) + 2칸 이동해서 1칸 전으로 온 경우(1칸 이동) 중 최댓값값
       dp[i] = max(dp[i-2], dp[i-3]+score[i-1]) + score[i];

    return dp[n];
}

int main(){
    int n;

    // 입력
    cin >> n;
    vector<int> score(n+1, 0);
    for (int i=1; i<=n; i++)
        cin >> score[i];

    // 연산 + 출력
    cout << maxScore(n, score);
}