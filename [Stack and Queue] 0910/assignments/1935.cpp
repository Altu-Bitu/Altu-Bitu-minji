//
// Created by Kang Minji on 2021-09-15.
//

#include <iostream>
#include <stack>
using namespace std;
int alphabet[26];

double calcOp(double num1, double num2, char op){
    switch(op){
        case '+':
            return num1+num2;
        case '-':
            return num1-num2;
        case '*':
            return num1*num2;
        case '/':
            return num1/num2;
    }
}

int main(){
    int n;
    double num1, num2;
    string str;

    cin >> n >> str;
    for (int i=0; i<n; i++)
        cin >> alphabet[i];

    stack<double> s;
    for (int i=0; i<str.length(); i++){
        // 01. 피연산자인 경우
        if (isupper(str[i])) {
            s.push(alphabet[str[i]- 'A']);
            continue;
        }
        // 02. 연산자인 경우
        num1 = s.top();
        s.pop();
        num2 = s.top();
        s.pop();
        // num2가 num1보다 크다(input 기준 더 뒤쪽)
        s.push(calcOp(num2, num1, str[i]));
    }

    // 03. 최종값 꺼내기
    cout << fixed;
    cout.precision(2);
    cout << s.top();
}