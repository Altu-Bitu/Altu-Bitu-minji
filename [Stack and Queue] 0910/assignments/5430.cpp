//
// Created by Kang Minji on 2021-09-15.
//

#include <iostream>
#include <string> // stoi
#include <queue>

using namespace std;

int main(){
    int t, n;
    string p, data;
    cin >> t;
    while (t--){
        cin >> p >> n >> data;

        string str = "";
        deque<int> dq;

        // 01. dq에 값 넣기
        for (auto iter : data){
            if (isdigit(iter))
                str += iter; // 42같이 숫자 붙어서 나올 수 있음
            else if (str != ""){ // 조건문 필요함...
                dq.push_back(stoi(str));
                str = "";
            }
        }

        // 02. 함수 수행하기
        // isReversed : bool로 만들어서 제일 나중에 뒤집기
        // isError : 에러나면 출력 X
        bool isReversed = false, isError = false;

        for (auto & function : p){
            if (function == 'R') {
                if (isReversed)
                    isReversed = false;
                else
                    isReversed = true;
            }
            else{ // "D"인 경우
                if (dq.empty()) {
                    cout << "error\n";
                    isError = true;
                    break; // break 안 하면 부가 연산함.
                }
                if (isReversed) // 뒤집힌 경우 -> 마지막 숫자 삭제
                    dq.pop_back();
                else // 멀쩡한 경우 -> 첫 번째 숫자 삭제
                    dq.pop_front();
            }
        }

        // 03. 출력하기
        if (!isError) {
            cout << "[";
            while(!dq.empty()) {
                if (isReversed) {
                    cout << dq.back();
                    dq.pop_back();
                }
                else {
                    cout << dq.front();
                    dq.pop_front();
                }
                if (!dq.empty()) // 원소가 더 남아있으면 ',' 출력
                    cout << ",";
            }
            cout << "]\n";
        }

    }
}
