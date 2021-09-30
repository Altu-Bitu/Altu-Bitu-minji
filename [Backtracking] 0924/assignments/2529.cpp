//
// Created by Kang Minji on 2021-09-30.
//

// 미완
#include <iostream>
using namespace std;
const int SIZE = 9;

int k;
char sign[SIZE+1]; // 부등호
bool check[SIZE+1]; // 부등호의 앞뒤에 들어갈 숫자

bool isValid(){
    for (int i=0; i<sign; i++){
        if ()
    }
}

void backtracking(int cnt){
    if (cnt == k){
        if check()
    }
    for (int i=0; i<=9; i++){
        if (!check[i]){
            check[i] = true;
            backtracking(cnt+1);
            check[i] = false;
        }
    }
}

int main(){

    // 입력
    cin >> k;
    for (int i=0; i<k; i++){
        cin >> sign[0];
    }

    // 연산 + 출력
    backtracking(0);

}