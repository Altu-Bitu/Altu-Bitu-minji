//
// Created by Kang Minji on 2021-10-04.
//

#include <iostream>
using namespace std;
const int MOD = 1000000000;
/*
* 1) 1~8일 떄 : dp[i][j] = dp[i-1][j-1]+dp[i-1][j+1]
* 2) 0일 때 : dp[i-1][j+1]
* 3) 9일 때 : dp[i-1][j-1]
*/
void makeSteps(int n){
    long long dp[101][10];
    long long ans = 0;

    // 한 자리 숫자의 계단 수
    // dp[i][j] = 길이가 i일 때 마지막 숫자가 j인 경우의 수
    for (int i=1; i<=9; i++)
        dp[1][i] = 1;

    for (int i=2; i<=n; i++){
        for (int j=0; j<10; j++){
            if (j == 0)
                dp[i][j] = dp[i-1][j+1];
            else if (j == 9)
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%MOD;
        }
    }

    for (int j=0; j<10; j++)
        ans += dp[n][j];

    cout << ans%MOD << "\n";

}

int main(){
    int n;
    cin >> n;

    makeSteps(n);
}
