//
// Created by Kang Minji on 2021-10-09.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> switches;
vector<pair<int, int>> student;

// Conquer : 스위치 번호가 given_num의 배수이면 스위치 상태를 바꾼다
// 스위치 전체 개수, 학생이 받은 수를 인자로 사용
void onoffBoy(int n, int given_num){
    for (int i=given_num; i<=n; i+=given_num)
        switches[i] = !switches[i];
}

// Conquer : 자기가 받은 수 기준 대칭인 최대 범위 구함 -> 그 안에 있는 스위치 reverse
void onoffGirl(int n, int given_num){
    // 00. 자기 switch 바꾸기
    switches[given_num] = !switches[given_num];
    // 01. given_num 기준 양쪽으로 범위 넓힘
    for (int i=1; i<given_num; i++){
        // 기저조건
        if (given_num + i > n || switches[given_num - i] != switches[given_num + i])
            break;
        // 02. 범위 내의 switch reverse
        switches[given_num - i] = !switches[given_num - i];
        switches[given_num + i] = !switches[given_num + i];
    }
}

int main(){
    int n, std_num;

    // 입력
    cin >> n;
    switches.assign(n+1, 0); // 인덱스 1부터 시작해야함
    for (int i=1; i<=n; i++)
        cin >> switches[i];

    cin >> std_num;
    student.assign(std_num, {0, 0});

    // 연산(받을 때마다 스위치 상태 바꿔줘야 함)
    for (int i=0; i<std_num; i++) {
        // Divide
        cin >> student[i].first >> student[i].second;
        if (student[i].first == 1) // 남학생인 경우
            onoffBoy(n, student[i].second);
        else // 여학생인 경우
            onoffGirl(n, student[i].second);
    }

    // 출력
    for (int i=1; i<n+1; i++) {
        cout << switches[i] << " ";
        // 한 번에 20개씩 출력
        if (i%20 == 0)
            cout << "\n";
    }
}