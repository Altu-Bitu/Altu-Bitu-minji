//
// Created by Kang Minji on 2021-09-30.
//

#include <iostream>
#include <set>
using namespace std;
const int SIZE = 7;

int n, m, num;
set<int> s; // 입력받은 숫자(중복 제거)
int result[SIZE]; // 출력할 수열

void backtracking(int cnt){
    if (cnt == m){
        for (int i=0; i<cnt; i++)
            cout << result[i] << ' ';
        cout << "\n";
        return;
    }
    for (auto iter : s){
        result[cnt] = iter;
        backtracking(cnt+1);
    }
}


int main(){

    // 입력
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> num;
        s.insert(num);
    }

    // 연산+출력
    backtracking(0);

}