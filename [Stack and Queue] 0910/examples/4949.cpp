//
// Created by Kang Minji on 2021-09-10.
//

#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string input){
    stack<char> s;

    for (int i=0; i<input.size(); i++){
        switch(input[i]){
            case '(': case'[':
                s.push(input[i]);
                break;

             case ')': case ']':
                 if (s.empty() || s.top() != bracket[input[i]])
                    return false;
                 s.pop();
                 break;
        }

        // return true; // '()(' 반례
        return s.empty();
    }
}


int main(){
    string input;

    while(true){
        getline(cin, input); // 띄어쓰기 포함 입력 받기
        if (input == ".")
            break;

        // 연산 & 출력
        // input에 대해 괄호 맞는지 확인
        cout << ((isBalanced((input))) ? "yes" : "no") << "\n";
    }
}