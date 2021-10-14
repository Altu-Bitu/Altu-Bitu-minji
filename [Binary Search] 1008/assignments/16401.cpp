//
// Created by Kang Minji on 2021-10-14.
//

// howmanyPeople 안의 for문이 실행되지 않음

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int m, n;

vector<int> snack;

int howManyPeople(int mid){
    int cnt = 0;
    // 과자를 나눠줄 수 있는 최대 인원 수
    for (int i=0; i<n; i++) {
        cnt += snack[i] / mid; // mid 길이만큼 과자 자름
    }

    return cnt;
}

int binarySearch(int left, int right){
    int max_length = 0; // 조카에게 줄 수 있는 최대 과자 길이

    while(left<=right){
        int mid = (left+right)/2; // 막대 길이
        // 01. 막대 길이가 mid일 때 몇 명한테 줄 수 있는가 확인
        int people = howManyPeople(mid);
        // 02. 조카 수보다 더 많이 나눠줄 수 있는 경우 -> 막대 길이 늘리기
        if (people >= m){
            max_length = mid; // 일단 막대 길이 저장
            left = mid+1;
        }
        // 03. 조카 수만큼 나눠줄 수 없음 -> 막대 길이 줄이기
        else
            right = mid-1;
    }
    return max_length;
}

int main(){
    int m, n;

    // 입력
    cin >> m >> n;
    snack.assign(n, 0);
    for (int i=0; i<n; i++)
        cin >> snack[i];

    // 연산
    sort(snack.begin(), snack.end());
    // 연산 + 출력 -> 과자 최소 길이 : 1, 최대 길이 : snack[n-1];
    cout << binarySearch(1, snack[n-1]);

}