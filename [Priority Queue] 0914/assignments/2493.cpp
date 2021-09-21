//
// Created by Kang Minji on 2021-09-20.
//

/*
 * 1) 현재 탑보다 낮고
 * 2) 오른쪽에 위치한 탑
 * 3) 그 중 가장 가까운 탑이 수신
 * */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    stack<pair<int, int>> s; // {높이, 인덱스}
    for (int i=0; i<n; i++)
        cin >> v[i];

    // 01. 제일 왼쪽에 있는 탑
    s.push({v[0], 1});
    cout << "0" << " ";

    // 02. 왼쪽부터 수신 가능한 탑 있는지 탐색
    for (int i=1; i<n; i++){
        bool flag = false;
        while(!s.empty()) {
            // 수신 가능한 탑이 있는 경우
            if (s.top().first >= v[i]) {
                cout << s.top().second << " ";
                flag = true;
                break;
            }
            // 수신탑 찾을 때까지 계속 pop
            s.pop();
        }
        // 수신탑이 없는 경우
        if (!flag)
            cout << 0 << " ";
        // 현재 높이와 인덱스+1을 스택에 넣기
        s.push({v[i], i + 1});
    }
}