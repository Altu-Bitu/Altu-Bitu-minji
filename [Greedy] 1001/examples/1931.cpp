//
// Created by Kang Minji on 2021-10-01.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

// 시작 시간말고 끝나는 시간 빠른 순서대로 정렬해야 한다
bool compare(const ci &a, const ci &b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int maxMeeting(int n, vector<ci> &meeting){
    int end = meeting[0].second; // 처음 회의의 끝나는 시간 저장
    int cnt = 1; // 처음 회의는 무조건 진행함!
    for (int i=1; i<n; i++){
        // 다음 회의의 시작 시간이 현재 회의의 끝나는 시간보다 클 경우 배치
        if (end <= meeting[i].first){
            cnt++;
            end = meeting[i].second;
        }
    }
    return cnt;
}

int main(){
    int n;

    // 입력
    cin >> n;
    vector<ci> meeting(n);
    for (int i=0; i<n; i++)
        cin >> meeting[i].first >> meeting[i].second;

    // 연산 + 출력
    sort(meeting.begin(), meeting.end(), compare);
    cout << maxMeeting(n, meeting);
}
