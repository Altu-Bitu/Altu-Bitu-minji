//
// Created by Kang Minji on 2021-10-07.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> straw;

// 삼각형 가능 조건 : 가장 긴 변 < 나머지 두 변의 합
int makeTriangle(int n){
    int max_length = -1;
    int a, b, c;
    for (int i=0; i<n-2; i++){ // for문 3개 돌리면 시간초과
        a = straw[i];
        b = straw[i+1];
        c = straw[i+2];
        // 각 변의 최댓값을 구한다 -> 이미 오름차순 정렬했으므로 삼각형 만족하면 바로 return
        if (a < b+c) {
            max_length = a + b + c;
            return max_length;
        }
    }
    return max_length;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    // 입력
    cin >> n;
    straw.assign(n, 0);
    for (int i=0; i<n; i++)
        cin >> straw[i];
    sort(straw.begin(), straw.end(), greater<>()); // 내림차순으로 정렬

    // 연산 + 출력
    cout << makeTriangle(n);
}