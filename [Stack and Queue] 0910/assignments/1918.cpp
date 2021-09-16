//
// Created by Kang Minji on 2021-09-15.
//

// 후위표기식 연산자 순위 : 우선 순위가 낮은 연산자부터 큰 연산자 순으로 쌓인다
#include <iostream>
#include <stack>
#include <map>
using namespace std;

stack<char> s;
map<char, int> m; // 연산자 우선순위

string findPostfix(string str){
    string answer = "";

    for (int i=0; i<str.length(); i++) {
        // 00. 대문자 알파벳 : 바로 출력
        if (isupper(str[i])) {
            answer += str[i];
            continue;
        }

        switch (str[i]) {
            // 01. '('인 경우 : 스택에 넣기
            case '(':
                s.push(str[i]);
                break;
            case ')':
                // 02. ')'인 경우 : '(' 나올 때까지 pop + '('도 pop
                while (!s.empty() && s.top() != '(') {
                    answer += s.top();
                    s.pop();
                }
                s.pop(); // '(' 없애기
                break;
            default :
                // 03. '*', '/', '+' ,'-'인 경우 : 스택의 top보다 현재 연산자 우선 순위 높거나 같을 때까지 pop
                while (!s.empty() && m[s.top()] >= m[str[i]]) {
                    answer += s.top();
                    s.pop();
                }
                s.push(str[i]);
                break;
        }
    }
    return answer;

}

int main(){
    m['+'] = 1;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 2;
    string str;
    cin >> str;

    // 후위표기식 연산자 순위 : 우선 순위가 낮은 연산자부터 큰 연산자 순으로 쌓인다
    cout << findPostfix(str);

    // 04. 스택에 남아있는 연산자들 출력
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}