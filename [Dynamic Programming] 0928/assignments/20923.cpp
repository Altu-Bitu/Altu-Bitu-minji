//
// Created by Kang Minji on 2021-10-03.
//

#include <iostream>
#include <queue>
using namespace std;

deque<int> deq[2]; // 각자의 덱(0: 도도, 1:수수)
deque<int> ground[2]; // 그라운드에 놓인 카드들

int findTop(){
    // 도도가 이기는 경우
    if ((!ground[0].empty() && ground[0].front() == 5) || (!ground[1].empty() && ground[1].front() == 5))
        return 0;
    // 수수가 이기는 경우
    if (!ground[0].empty() && !ground[1].empty() && ground[0].front() + ground[1].front() == 5)
        return 1;
    return 2; // 아무도 카드 못 가져감
}

int main(){
    int n, m;
    int n1, n2;

    // 입력
    cin >> n >> m;

    while(n--){
        cin >> n1 >> n2;
        deq[0].push_front(n1);
        deq[1].push_front(n2);
    }

    // 연산
    int turn = 0; // 도도부터 시작
    while(m--){
        // 그라운드에 내려놓기
        ground[turn].push_front(deq[turn].front());
        deq[turn].pop_front();

        // 게임 도중 덱에 있는 카드의 수가 0개가 되는 경우
        if (deq[turn].empty()){
            if (turn == 0)
                cout << "su\n";
            else
                cout << "do\n";
            return 0;
        }

        // 가장 위에 위치한 카드 식 판별
        int winner = findTop();
        int loser = abs(winner - 1);

        // 아무도 못 가져가는 경우 턴만 바꾸고 진행
        if (winner == 2){
            turn = abs(turn-1);
            continue;
        }

        // 01. 상대방의 그라운드에 있는 카드 더미 뒤집어 아래로 합침
        while(!ground[loser].empty()){
            deq[winner].push_back(ground[loser].back());
            ground[loser].pop_back();
        }

        // 02. 자신의 그라운드에 있는 카드 뒤집어 아래로 합침
        while (!ground[winner].empty()) {
            deq[winner].push_back(ground[winner].back());
            ground[winner].pop_back();
        }
        turn = abs(turn - 1);
    }

    // 출력
    if (deq[0].size() > deq[1].size())
        cout << "do\n";
    else if (deq[0].size() < deq[1].size())
        cout << "su\n";
    else
        cout << "dosu\n";
}