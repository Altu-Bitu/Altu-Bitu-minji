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