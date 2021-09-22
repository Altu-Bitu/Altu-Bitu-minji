//
// Created by Kang Minji on 2021-09-23.
//

#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n, p, line, pret;
    int cnt = 0;

    cin >> n >> p;
    stack<int> s[7]; // 줄의 수와 음의 수를 헷갈리지 말자...
    while (n--) {
        cin >> line >> pret;
        // 01. 해당 줄이 비었다면 추가 + 2) 현재 입력받은 프렛이 높으면 추가
        if (s[line].empty()) {
            s[line].push(pret);
            cnt++;
            continue;
        }
        // 02. 해당 줄이 비어있지 않고,
        else {
            // 1) 현재 입력받은 프렛이 낮으면 top이 입력받은 프렛보다 작거나 같을 때까지 pop
            if (s[line].top() > pret) {
                while (!s[line].empty() && s[line].top() > pret) {
                    s[line].pop();
                    cnt++;
                }
            }
            // 2) 현재 입력받은 프렛과 같으면 넘어가기
            if (!s[line].empty() && s[line].top() == pret) {
                continue;
            }
            // 3) 현재 입력받은 프렛이 높으면 추가
            s[line].push(pret);
            cnt++;
        }
    }
    cout << cnt;
}