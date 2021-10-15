//
// Created by Kang Minji on 2021-10-14.
//

#include <iostream>
#include <map>
using namespace std;

map<int, string> setting;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, power;
    string name;

    // 입력
    cin >> n >> m;
    while(n--){
        cin >> name >> power;
        setting.insert(make_pair(power, name));
    }

    map<int, string>::iterator iter;
    while(m--){
        cin >> power;
        // lower bound : 찾으려 하는 key값이 없으면 key값보다 큰 가장 작은 정수값 반환
        // iterator 형식 반환
        iter = setting.lower_bound(power);
        // 출력
        cout << iter -> second << "\n";
    }
}