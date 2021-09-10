//
// Created by Kang Minji on 2021-09-10.
//

// 답이 다르게 나옴
#include <iostream>
#include <map>
using namespace std;
int p_sum[200001];

int main(){
    int n, k, num;
    cin >> n >> k;
    map<int, int> m;

    long long cnt = 0;
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