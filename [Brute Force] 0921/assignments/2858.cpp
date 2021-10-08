//
// Created by Kang Minji on 2021-09-27.
//

#include <iostream>
using namespace std;

void findRoomSize(int r, int b){
    // r = 8부터 시작, b = 1부터 시작 -> 최소 사이즈 3*3
    for (int i=3;;i++){ // 가로
        for (int j=3;j<=i;j++){ // 세로
            if (r == (2*i + 2*j - 4) && b == (i-2)*(j-2)) {
                cout << i << " " << j;
                return;
            }
        }
    }
}

int main(){
    int r, b;
    cin >> r >> b;

    findRoomSize(r, b);
}