//
// Created by Kang Minji on 2021-10-11.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> p; // 행렬 저장

// Conquer : 2*2에서 두 번째로 큰 수 리턴
// 함수 호출을...너무 많이 하는 것 아닌가
int pooling(int i, int j){
    vector<int> tmp;
    for (int a=i; a<i+2; a++)
        for(int b=j; b<j+2; b++)
            tmp.push_back(p[a][b]);

    sort(tmp.begin(), tmp.end(), greater<>());
    return tmp[1];
}

int main(){
     int n;
     // 입력
     cin >> n;
     p.assign(n, vector<int>(n, 0));

     for (int i=0; i<n; i++)
         for (int j=0; j<n; j++)
            cin >> p[i][j];

     // 연산
     while(n>1) { // n 사이즈 줄여감
         // Divide
         for (int i = 0; i < n; i += 2) {
             for (int j = 0; j < n; j += 2) {
                 // 2*2 정사각형에서 2번째로 큰 수를 줄어든 행렬의 인덱스에 대입
                 p[i / 2][j / 2] = pooling(i, j);
             }
        }
        n/=2; // 모든 정사각형에 대해 pooling 끝나면 size 반으로 줄임
     }

     cout << p[0][0];
}

// 샘플 코드
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> matrix;

int divide(int row, int col, int size) {
    //Conquer : n의 크기가 1
    if (size == 1)
        return matrix[row][col];

    //Divide : 행렬 4등분 하기
    int next_size = size / 2; // 핵심 파트! 2*2로 나누는 것이 아니라 현재 행렬 사이즈/2를 함!!
    vector<int> sub_problem;
    for (int i = 0; i <= next_size; i += next_size) {
        for (int j = 0; j <= next_size; j += next_size)
            sub_problem.push_back(divide(row + i, col + j, next_size));
    }

    //Combine : 두번째로 큰 수만 남기기
    sort(sub_problem.begin(), sub_problem.end(), greater<>());
    return sub_problem[1];
}

/**
 * 1. 행렬 4등분 하기
 * 2. 행렬의 크기가 1이라면 원소 리턴
 * 3. 리턴된 원소 4개 모아서 두번째로 큰 수만 리턴
 */
int main() {
    int n;

    //입력
    cin >> n;
    matrix.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    //연산 & 출력
    cout << divide(0, 0, n);
}