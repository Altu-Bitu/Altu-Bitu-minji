//
// Created by Kang Minji on 2021-10-01.
//

#include <string>
#include <vector>
using namespace std;

/*
 * 학생의 체육복 개수 표시
 * 왼쪽 학생부터 양 옆의 학생에게 체육복을 빌릴 수 있는지 검사
 * 체육복이 1개 이상인 학생의 개수를 세준다.
 */
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    // 학생 번호 1번부터 시작 -> n+1
    vector<int> student(n+1, 1);

    // 01-1) 체육복 잃어버린 학생
    for (int i=0; i<lost.size(); i++)
        student[lost[i]]--;

    // 01-2) 체육복 여분으로 있는 학생
    for (int i=0; i<reserve.size(); i++)
        student[reserve[i]]++;

    // 02. 양 옆의 학생에게 체육복 빌릴 수 있는지 검사
    for (int i=1; i<=n; i++){
        if (student[i]) // 체육복이 있는 학생들
            continue;
        if (student[i-1] == 2){ // 왼쪽 학생한테 빌리는 경우
            student[i-1]--;
            student[i]++;
        }
        else if (student[i+1] == 2){ // 오른쪽 학생한테 빌리는 경우
            student[i+1]--;
            student[i]++;
        }
    }

    // 03. 전체 학생 벡터를 돌면서 체육복 있는 사람 검사
    for (int i=1; i<=n; i++){
        if (student[i])
            answer++;
    }
    return answer;
}