//
// Created by KangMinji on 2021-11-12.
//
// https://conkjh032.tistory.com/289
// 플로이드-워셜 사용
#include <iostream>
#include <vector>
using namespace std;

void floydWarShall(int n, vector<vector<bool>> event){
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (event[i][k] && event[k][j])
                    event[i][j] = true; // 사건 선후관계 유추
            }
        }
    }
}

int main(){
    int n, k, s, num1, num2;

    // 입력
    cin >> n >> k;
    vector<vector<bool>> event(n+1, vector<bool>(n+1));
    for (int i=0; i<k; i++){
        cin >> num1 >> num2;
        event[num1][num2] = true; // 굳이 반대 방향까지 표시 x
    }

    // 연산
    floydWarShall(n, event);

    cin >> s;
    // 출력
    for (int i=0; i<s; i++){
        cin >> num1 >> num2;
        if (event[num1][num2])
            cout << "-1";
        else if (event[num2][num1])
            cout << "1";
        else
            cout << "0";
        cout << "\n";
    }
}