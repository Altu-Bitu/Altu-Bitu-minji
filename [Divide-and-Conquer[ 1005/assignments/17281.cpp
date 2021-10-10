//
// Created by Kang Minji on 2021-10-11.
//
// 참고 : https://11001.tistory.com/27

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result; // (선수 번호, {각 이닝에서의 득점})
vector<int> order(10, 0); // 타순, 선수 번호
vector<int> player(9); // 순열 만들 때 선택되었는지 여부
vector<bool> base; // 베이스에 누구 있는지

// 플레이 진행되는 동안 선수들 위치(베이스) 이동시킴
void move(int score, int &sum){
    // 3루부터 1루까지 역으로 보면서
    for (int i=3; i>0; i--){
        if (base[i]){
            if (i+score >= 3) // 홈런 칠 수 있는 경우
                sum++;
            else
                base[i+score] = true;
            base[i] = false;
        }
    }
    // 홈런인 경우
    if (score == 4)
        sum++;
    else
        base[score-1] = true;
}

// 게임 플레이
int play(int inning){
    int sum = 0, score = 0;
    int idx = 1; // 타자 1번부터 시작
    int cur_order = order[idx]; // 현재 타자

    for(int i=0; i<inning; i++){
        // 아웃, 베이스 초기화
        int out_cnt = 0;
        base.assign(4, false);

        while(out_cnt < 3){
            score = result[cur_order][i];
            // 1) 아웃되는 경우
            out_cnt++;
            // 2) 정상적 플레이
            move(score, sum);
            // 플레이 끝나면
            idx++;
            if (idx > 9) // 모든 선수 다 치면 1번으로
                idx = 1;
            cur_order = order[idx];
        }
    }
}

int main(){
    int n, ans=-1;

    // 입력
    cin >> n; // 이닝 수
    result.assign(n, vector<int>(n, 0));

    for (int i=0; i<9; i++)
        for (int j=0; j<n; j++)
            cin >> result[i][j];

    // 선수 번호들 순서대로 넣어놓기
    for (int i=0; i<9; i++)
        player[i] = i;

    // 연산 : 순열(조합X) 이용해서 타순 정하기
    do{
        for (int i=0; i<3; i++)
            order[i+1] = player[i];
        order[4] = 1; // 1번 선수를 4번 타자로 결정함
        for (int i=4; i<9; i++)
            order[i+1] = player[i];
        ans = max(ans, play(n));
    } while(next_permutation(player.begin(), player.end())); // player를 1~10으로 할 수 없는 이유....

    // 출력
    cout << ans;
}