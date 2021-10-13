//
// Created by Kang Minji on 2021-10-10.
//

// 312ms
#include <iostream>
using namespace std;

void makeStar(int i, int j, int n) {
    // 빈 칸 만들기
    if ((i/n) % 3 == 1 && (j/n) % 3 == 1) {
        cout << " ";
        return;
    }
    // 한 칸으로 줄어들면 그 때 별 찍기
    if (n == 1)
        cout << "*";
    // 재귀
    else makeStar(i, j, n / 3);
}

int main() {
    int n;
    // 입력
    cin >> n;

    // 연산 + 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            makeStar(i, j, n);
        }
        cout << "\n";
    }
}

// 180ms
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> star;

// 아예 3*3이라고 가정하고 풀이
void makeStar(int i, int j, int n){
    // Conquer : 빈 자리 아닌 곳에 별 찍기
    if (n==1){
        star[i][j] = '*';
        return;
    }

    // Divide
    for (int p=0; p<3; p++){
        for (int q=0; q<3; q++){
            if (p==1 && q==1) // 빈 칸이면
                continue;
            makeStar(i+p*n/3, j+q*n/3, n/3); // 좌표 이동해줌
        }
    }
}

int main(){
    int n;

    // 입력
    cin >> n;
    star.assign(n, vector<char>(n, ' '));

    // 연산
    makeStar(0,0,n);

    // 출력
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            cout << star[i][j];
        cout << "\n";
    }
}
