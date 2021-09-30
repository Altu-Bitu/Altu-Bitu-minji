//
// Created by Kang Minji on 2021-09-30.
//

#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 9;

int k;
char brackets[SIZE+1]; // 부등호
bool check[SIZE+1]; // 숫자 사용 여부
vector<int> used_num; // 사용된 숫자들
string max_num = "0123456789", min_num = "9876543210";

// cnt번째로 사용되는 숫자가 valid한 지 검사
void backtracking(int cnt){
    if (cnt == k+1){
        string num = "";
        for (int i=0; i<used_num.size(); i++)
            num += to_string(used_num[i]);
        max_num = max(max_num, num);
        min_num = min(min_num, num);
    }
    for (int i=0; i<10; i++){
        if (!check[i]){
            check[i] = true;
            used_num.push_back(i);
            // 01. i가 첫 번째 숫자인 경우
            if (cnt == 0)
                backtracking(cnt+1); // 다음 차례로 넘어감
                // 02. 이전 단계와 현재 단계 숫자 검사하기
            else if ((brackets[cnt-1] == '<' && used_num[used_num.size()-2] < i) ||
                     (brackets[cnt-1] == '>' && used_num[used_num.size()-2] > i))
                backtracking(cnt+1);
            check[i] = false;
            used_num.pop_back();
        }
    }
}

int main(){

    // 입력
    cin >> k;
    for (int i=0; i<k; i++){
        cin >> brackets[i];
    }

    // 연산 + 출력
    backtracking(0);
    cout << max_num << "\n" << min_num;
}