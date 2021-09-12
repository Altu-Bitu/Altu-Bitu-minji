//
// Created by Kang Minji on 2021-09-10.
//

#include <iostream>
#include <map>
using namespace std;
int p_sum[200001];

int main(){
    int n, k, num;
    cin >> n >> k;
    map<int, long long> m; // 부분합 개수 : 2000000000*(2000000000+1)/2

    long long cnt = 0;
    m[0] = 1; // p_sum[i]가 k인 경우, j=0이 될 수 있음

    for (int i=1; i<=n; i++){
        cin >> num;
        // 01. 각각의 부분합을 저장
        p_sum[i] = p_sum[i-1] + num;
        // * 1~n까지 i를 돌면서 sum[i] - sum[j] = k를 만족하는 j가 있는지 검사(i>=j라고 가정! - 문제와 기호 다르게 써도 상관X)
        // 만약 존재하면 ans++;
        // sum[j] = sum[i] - k
        cnt += m[p_sum[i] - k];
        // 02. map에 저장
        m[p_sum[i]]++;
    }
    cout << cnt;
}