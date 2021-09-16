//
// Created by Kang Minji on 2021-09-07.
//

#include <iostream>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    string input;
    map<string, int> name;
    map<int, string> number;

    cin >> n >> m;
    // 포켓몬 번호 : 1번 ~ n번
    for (int i=1; i<=n; i++){
        cin >> input;
        name[input] = i; // 이름 도감에 저장
        number[i] = input; // 번호 도감에 저장
    }

    while(m--){
        cin >> input;
        if (isdigit(input[0])) // 숫자면 번호 도감 참조
            cout << number[stoi(input)] << "\n";
        else
            cout << name[input] << "\n";
    }
}