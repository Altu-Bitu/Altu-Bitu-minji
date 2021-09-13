//
// Created by Kang Minji on 2021-09-10.
//

#include <iostream>
#include <stack>
#include <map>
using namespace std;

// 괄호의 짝을 저장할 맵
map<char, char> bracket;

// 괄호가 균형을 이루었는지 확인하는 함수
bool isBalanced(string input){
    stack<char> s;

    for (int i=0; i<input.size(); i++){
        switch(input[i]){
            case '(': case '[': // 왼쪽 괄호
                s.push(input[i]);
                break;
            case ')': case ']': // 오른쪽 괄호
                if (s.empty() || s.top() != bracket[input[i]])
                    return false;
                s.pop();
                break;
        }
    }
    // return true; // '()(' 반례
    return s.empty();
}

int main(){
    string input;
    // 짝 설정
    bracket[')'] = '(';
    bracket[']'] = '[';

    while(true){
        getline(cin, input);

        if (input == ".")
            break;

        if (isBalanced(input))
            cout << "yes\n";
        else
            cout << "no\n";
    }
}