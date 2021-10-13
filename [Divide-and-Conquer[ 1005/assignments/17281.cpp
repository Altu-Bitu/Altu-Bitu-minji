//
// Created by Kang Minji on 2021-10-11.
//
// 참고 : https://11001.tistory.com/27

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int score, player; // score : 각 이닝에서 얻는 총 득점, player = 현재 주자
vector<int> entry = {0, 1, 2, 3, 4, 5, 6, 7, 8}; //선수 순서
vector<vector<int>> board; // 각 선수가 이닝에서 얻는 결과

/**
 * 주자들 진루처리
 *
 * 1110 : 1, 2, 3루에 주자 존재
 * 0100 : 2루에 주자 존재
 * 1010 : 1, 3루에 주자 존재
 */
// 각 주자 이동시켜주는 함수
void running(int &run, int num) {
    run |= (1 << 0); //0번 플레이트에 타자 표시
    for (int i = (4 - num); i < 4; i++) { //홈까지 진루할 수 있는 주자들
        if (run & (1 << i)) { //주자가 있다면
            run &= ~(1 << i); //주자가 홈인 했기 때문에 플레이트를 비워줌
            score++; // 점수 증가
        }
    }
    run = run << num; //주자들 이동
}

//idx 이닝 플레이
void playGame(int idx) {
    int out = 0, run = 0; //아웃카운트, 진루 상태
    while (out != 3) { // 3아웃이 발생하지 않은 상태면 플레이함
        int hit = board[idx][entry[player]]; //이번 주자의 결과
        if (!hit) //아웃
            out++; // 아웃 카운트 증가
        else //존재하는 모든 주자 진루
            running(run, hit); // 각 주자 이동시켜줌
        player = (player + 1) % 9; //다음 선수
    }
}

/**
 * 순열, 비트마스킹 풀이
 * 1. 순열로 가능한 모든 타순을 구한다. (순열)
 *    4번 타자는 항상 1번 선수여야 하기 때문에 2번 ~ 9번 선수에 대해서만 순열을 돌린다.
 * 2. 엔트리에 대한 점수를 계산한다. 1~3루와 홈베이스 총 4개의 플레이트에 대해 선수의 존재여부를 비트로 표현한다.
 *
 * 해설 : https://myunji.tistory.com/439?category=1154147
 */
int main() {
    int n, ans = 0; // 이닝 수, 가장 많은 득점

    //입력
    cin >> n; // 이닝 수 입력받음
    board.assign(n, vector<int>(9)); // 각 선수가 이닝에서 얻는 결과 벡터 초기화
    for (int i = 0; i < n; i++) { // n만큼의 이닝에서
        for (int j = 0; j < 9; j++) // 선수 9명의 결과를
            cin >> board[i][j]; // 벡터에 입력받음
    }

    //연산
    do { // 가능한 모든 엔트리에 대해 돌려봄
        swap(entry[0], entry[3]); // 1번 선수 4번 타자 되도록
        score = player = 0; //초기화
        for (int i = 0; i < n; i++) //각 이닝별로 플레이
            playGame(i); // 해당 함수 호출
        ans = max(ans, score); // 가장 많은 득점 갱신
        swap(entry[3], entry[0]); // 선수 번호 원래대로 복구
    } while (next_permutation(entry.begin() + 1, entry.end())); // 순열 계산(조합 X)

    //출력
    cout << ans;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<vector<int>> result; // (선수 번호, {각 이닝에서의 득점})
//vector<int> order(10, 0); // 타순, 선수 번호
//vector<int> player(9); // 순열 만들 때 선택되었는지 여부
//vector<bool> base; // 베이스에 누구 있는지
//
//// 플레이 진행되는 동안 선수들 위치(베이스) 이동시킴
//void move(int score, int &sum){
//    // 3루부터 1루까지 역으로 보면서
//    for (int i=3; i>0; i--){
//        if (base[i]){
//            if (i+score >= 3) // 홈런 칠 수 있는 경우
//                sum++;
//            else
//                base[i+score] = true;
//            base[i] = false;
//        }
//    }
//    // 홈런인 경우
//    if (score == 4)
//        sum++;
//    else
//        base[score-1] = true;
//}
//
//// 게임 플레이
//int play(int inning){
//    int sum = 0, score = 0;
//    int idx = 1; // 타자 1번부터 시작
//    int cur_order = order[idx]; // 현재 타자
//
//    for(int i=0; i<inning; i++){
//        // 아웃, 베이스 초기화
//        int out_cnt = 0;
//        base.assign(4, false);
//
//        while(out_cnt < 3){
//            score = result[cur_order][i];
//            // 1) 아웃되는 경우
//            out_cnt++;
//            // 2) 정상적 플레이
//            move(score, sum);
//            // 플레이 끝나면
//            idx++;
//            if (idx > 9) // 모든 선수 다 치면 1번으로
//                idx = 1;
//            cur_order = order[idx];
//        }
//    }
//}
//
//int main(){
//    int n, ans=-1;
//
//    // 입력
//    cin >> n; // 이닝 수
//    result.assign(n, vector<int>(n, 0));
//
//    for (int i=0; i<9; i++)
//        for (int j=0; j<n; j++)
//            cin >> result[i][j];
//
//    // 선수 번호들 순서대로 넣어놓기
//    for (int i=0; i<9; i++)
//        player[i] = i;
//
//    // 연산 : 순열(조합X) 이용해서 타순 정하기
//    do{
//        for (int i=0; i<3; i++)
//            order[i+1] = player[i];
//        order[4] = 1; // 1번 선수를 4번 타자로 결정함
//        for (int i=4; i<9; i++)
//            order[i+1] = player[i];
//        ans = max(ans, play(n));
//    } while(next_permutation(player.begin(), player.end())); // player를 1~10으로 할 수 없는 이유....
//
//    // 출력
//    cout << ans;
//}