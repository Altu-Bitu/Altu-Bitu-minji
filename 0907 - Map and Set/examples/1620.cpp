//
// Created by Kang Minji on 2021-09-07.
//

#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, m;
    string input;
    map<string, int> name;
    map<int, string> number;

    // 입력
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> input;
        name[input] = 1; // key : 이름, value : 번호
        number[i] = input; // key : 번호, value : 이름
    }

    // 출력
    while(m--){
        cin >> input;
        if (isdigit(input[0])) // 입력이 숫자라면
            cout << number[stoi(input)] << "\n"; // stoi : string to int
        else
            cout << name[input] << "\n";
    }
}