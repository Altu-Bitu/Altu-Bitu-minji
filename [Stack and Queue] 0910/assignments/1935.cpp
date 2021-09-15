//
// Created by Kang Minji on 2021-09-15.
//

#include <iostream>
#include <stack>
using namespace std;
int alphabet[26];

int main(){
    int n;
    double a, b;
    string str;

    cin >> n >> str;
    for (int i=0; i<n; i++)
        cin >> alphabet[i];

    stack<double> s;
    for (int i=0; i<str.length(); i++){
        // 01. 연산자인 경우
        if (str[i] == '+' || str[i] == '-' || str[i] =='*' || str[i]=='/'){
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            switch(str[i]){
                // b가 a보다 크다(input 기준 더 뒤쪽)
                case '+':
                    s.push(b+a);
                    break;
                case '-':
                    s.push(b-a);
                    break;
                case '*':
                    s.push(b*a);
                    break;
                case '/':
                    s.push(b/a);
                    break;
            }
        }
        // 02. 피연산자인 경우
        else
            s.push(alphabet[str[i] - 'A']);
    }

    // 03. 최종값 꺼내기
    cout << fixed;
    cout.precision(2);
    cout << s.top();
}