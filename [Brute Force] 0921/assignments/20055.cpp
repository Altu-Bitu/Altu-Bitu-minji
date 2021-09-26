//
// Created by Kang Minji on 2021-09-27.
//

#include <iostream>
#include <vector>
using namespace std;

void rotateBelt(){

}

void moveRobot(){

}

void makeRobot(){

}

int findStep(int n, int k, vector<int> &durability){
    vector<int> robot(2*n); // 로봇의 위치
    int cnt = 0; // 내구도 0인 칸의 개수

    // 내구도 0이 되는 경우
    // 01. 올리는 칸의 내구도가 0
    // 02. 벨트 내부의 내구도가 0
    while (true){
        // 01. 벨트 회전
        rotateBelt();
        // 02. 로봇 이동
        moveRobot();
        // 03. 로봇 올리기
        makeRobot();
        if (cnt == k)
            return 0;
    }
}

int main(){
    int n, k;

    // 입력
    cin >> n >> k;
    vector<int> durability(2*n); // 컨베이어 벨트의 내구도를 저장

    for (int i=0; i<2*n; i++){
        cin >> durability[i];
    }

    // 연산 + 출력
    cout << findStep(n, k, durability)
}