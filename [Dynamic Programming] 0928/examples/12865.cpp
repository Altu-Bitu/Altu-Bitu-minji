//
// Created by Kang Minji on 2021-10-03.
//

#include <iostream>
#include <vector>
using namespace std;

struct info{
    int w, v;
};

int knapsack(int n, int k, vector<info> &product){
    vector<int> dp(k+1, 0); // 무게별 최대 가치 창출

    for (int i=1;i<=n;i++){
        for (int j=k;j>=product[i].w;j--) // j : 최대 배낭 무게
            dp[j] = max(dp[j-product[i].w]+product[i].v, dp[j]);
    }

    return dp[k];
}

int main(){
    int n, k;

    // 입력
    cin >> n >> k;
    vector<info> product(n+1, {0,0});
    for (int i=1;i<=n;i++)
        cin >> product[i].w >> product[i].v;

    // 연산 + 출력
    cout << knapsack(n, k, product);

}