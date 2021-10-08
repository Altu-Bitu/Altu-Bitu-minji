//
// Created by Kang Minji on 2021-09-27.
//

#include <iostream>
#include <vector>
using namespace std;

void maxPay(int date, int pay, int &max_pay, vector<pair<int, int>> &counseling) {
    // 모든 경우의 수 따짐 -> 각 경우의 퇴사일에서 max_pay를 계속 update한다

    // 퇴사일
    if (date == counseling.size()){
        max_pay = max(pay, max_pay);
        return;
    }
    // 일을 하는 경우
    if (date+counseling[date].first <= counseling.size()){
        maxPay(date+counseling[date].first, pay+counseling[date].second,max_pay,counseling);
    }
    // 일을 하지 않는 경우
    if (date + 1 <= counseling.size())
        maxPay(date + 1, pay, max_pay, counseling);

}

int main(){
    int n, max_pay = 0;

    // 입력
    cin >> n;
    vector<pair<int,int>> counseling(n); // 시간, 돈
    for (int i=0; i<n; i++)
        cin >> counseling[i].first >> counseling[i].second;

    // 연산
    maxPay(0, 0, max_pay, counseling);

    // 출력
    cout << max_pay;
}