//
// Created by Kang Minji on 2021-09-30.
//

#include <iostream>
using namespace std;

const int SIZE = 20;

int n;
int team[SIZE+1][SIZE+1];
bool check[SIZE+1]; // start팀 true, link팀 false
int diff = 2147483647; // start팀과 link팀 능력치 차이값

// 각 팀의 능력치 합 구하기 + 최솟값 갱신
void calcMin(){
    int start = 0, link = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            // start 팀에 ij, ji 능력치 더해준다
            if (check[i] && check[j])
                start += team[i][j];
                // link 팀에 ij, ji 능력치 더해준다
            else if (!check[i] && !check[j])
                link += team[i][j];
        }
    }
    // 03. 최솟값 갱신
    diff = min(abs(start-link), diff);
}

// cnt : start팀 팀원 수, idx = 팀 정할 팀원 번호(0부터 시작한다고 가정)
void backtracking(int cnt, int idx, int limit){
    // 02. 각 팀의 능력치 합 구하기
    if (cnt == limit){
        calcMin();
        return;
    }
    // 01. start팀 팀원 인덱스 오름차순으로 구하기
    for (int i=idx; i<=n; i++){
        if (!check[i]){
            check[i] = true;
            backtracking(cnt+1, i+1, limit);
            check[i] = false;
        }
    }
}

int main(){

    cin >> n;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> team[i][j];

    // start팀 인원 : 1명 ~ n-1명
    // (start팀, link팀의 인원수 같지 않아도 됨!!!)
    // 각각을 기저조건으로 backtracking 돌리기
    for (int i=1; i<n; i++)
        backtracking(0, 0, i);

    cout << diff << "\n";
}