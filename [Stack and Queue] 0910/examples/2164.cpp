//
// Created by Kang Minji on 2021-09-10.
//

#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    queue<int> q;

    cin >> n;
    for (int i=1; i<=n; i++)
        q.push(i);

    // 탈출 조건 : 카드가 한 장 남을 때까지
    while(q.size() != 1){
        // 01. 제일 위에 있는 카드 버리기
        q.pop();

        // 02. 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮기기
        int card = q.front();
        q.pop();
        q.push(card);
    }

    cout << q.front();
}