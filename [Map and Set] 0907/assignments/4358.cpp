//
// Created by Kang Minji on 2021-09-10.
//

#include <iostream>
#include <map>
using namespace std;

int main(){
    string name;
    int total_cnt = 0;
    map<string, double> m;

    while(getline(cin, name)){ // 공백 포함 한 줄씩 입력받기
        m[name]++;
        total_cnt++;
    }

    // 소수점 자리 고정(4자리)
    cout << fixed;
    cout.precision(4);

    for (auto & iter : m){
        cout << iter.first << " " << (iter.second/total_cnt)*100 << "\n";
        // double 안 써도 됨(int -> double 형변환)
    }
}