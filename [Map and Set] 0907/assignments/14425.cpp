//
// Created by Kang Minji on 2021-09-09.
//

#include <iostream>
#include <set>
using namespace std;

int main(){
    int n, m, cnt = 0;
    string input;
    set<string> s;

    cin >> n >> m;
    // 01. 집합 s에 포함되어 있는 문자열 입력
    while (n--){
        cin >> input;
        s.insert(input);
    }

    // 02. 검사해야 하는 문자열 입력
    while(m--){
        cin >> input;
        // 집합 s에 포함된 문자열인 경우
        if (s.count(input))
            cnt++;
    }
    cout << cnt;
}