//
// Created by Kang Minji on 2021-09-27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b){
    if (a.second == b.second)
        return a.first < b.first; // 최빈값 같으면 원래 값 작은 순서대로
    return a.second > b.second;
}

// 03. 최빈값 출력 -> 여러 개 있으면 최빈값 중 두 번째로 작은 값 출력
int findMode(vector<int> v, map<int, int> m, int n){
    // 벡터에 map(원래 수, 빈도 수) 넣기
    vector<pair<int, int>> mean(m.begin(), m.end());
    // 벡터 내림차순으로 정렬(이것 때문에 벡터에 다시 담음...)
    sort(mean.begin(), mean.end(), compare);

    // 1) 최빈값 1개인 경우 || 겹치는 최빈값 없는 경우
    if (mean.size() == 1 || mean[0].second != mean[1].second)
        return mean[0].first;
    return mean[1].first;

}

int main(){
    int n, mean=0;

    // 입력
    cin >> n;
    vector<int> v(n);
    map<int, int> m;

    for (int i=0; i<n; i++) {
        cin >> v[i];
        mean += v[i];
        m[v[i]]++;
    }

    sort(v.begin(), v.end());

    // 연산 + 출력
    cout << round((double)mean/n) << "\n";
    cout << v[n/2] << "\n";
    cout << findMode(v,m, n) << "\n";
    cout << v.back() - v.front() << "\n";

}