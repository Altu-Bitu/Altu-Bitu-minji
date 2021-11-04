//
// Created by Kang Minji on 2021-10-12.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, num;

    // 입력
    cin >> n >> m;
    vector<int> sum(n+1, 0);
    for (int i=1; i<=n; i++){ // 인덱스를 1부터 시작하면 i=0인 경우 따로 처리할 필요 없음
        cin >> num;
        sum[i] = sum[i-1]+num;
    }

    while(m--){
        int s, e;
        cin >> s >> e;

        // 출력
        cout << sum[e] - sum[s-1] << "\n";
    }

}