//
// Created by Kang Minji on 2021-09-15.
//

#include <iostream>
#include <stack>
using namespace std;
stack<char> s;

// 후위표기식 연산자 순위 : 우선 순위가 낮은 연산자부터 큰 연산자 순으로 쌓인다
void findPostfix(char ch){
    // 00. 알파벳 : 바로 출력
    if (ch >= 'A' && ch <= 'Z')
        cout << ch;
    else {
        switch (ch) {
            // 01. '('인 경우 : 스택에 넣기
            case '(':
                s.push(ch);
                break;
                // 02. '*', '/', '+' ,'-'인 경우 : 스택의 top보다 현재 연산자 우선 순위 높거나 같을 때까지 pop
            case '*':
            case '/':
                while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                    cout << s.top();
                    s.pop();
                }
                s.push(ch);
                break;
            case '+':
            case '-':
                while (!s.empty() && (s.top() != '(')) {
                    cout << s.top();
                    s.pop();
                }
                s.push(ch);
                break;
                // 03. ')'인 경우 : '(' 나올 때까지 pop + '('도 pop
            case ')':
                while (!s.empty() && (s.top() != '(')) {
                    cout << s.top();
                    s.pop();
                }
                s.pop(); // '(' 없애기
                break;
        }
    }
}

int main(){
    string str;
    cin >> str;

    // 후위표기식 연산자 순위 : 우선 순위가 낮은 연산자부터 큰 연산자 순으로 쌓인다
    for(int i=0; i<str.length(); i++){
        findPostfix(str[i]);
    }
    // 04. 스택에 남아있는 연산자들 출력
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}