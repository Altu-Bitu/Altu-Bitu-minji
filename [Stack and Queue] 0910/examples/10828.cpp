//
// Created by Kang Minji on 2021-09-10.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int SIZE = 10000;

int top_pointer = -1;
vector<int> stack_vec(SIZE);

// empty
bool empty(){
    return top_pointer == -1;
}

// full
bool full(){
    return top_pointer == SIZE -1;
}

// push
void push(int k){
    stack_vec[++top_pointer] = k;
}

// pop
int pop(){
    return stack_vec[top_pointer--];
}

// size
int size(){
    return top_pointer + 1;
}

// top
int top(){
    return stack_vec[top_pointer];
}

int main(){
    int n, k;
    string cmd;
    stack<int> s;

    cin >> n;
    while (n--){
        cin >> cmd;
        if (cmd == "push"){
            cin >> k;
//            if(!full()) // 라이브러리 사용시에는 필요 없음
//                s.push(k);
            s.push(k); // 크기제한 X
            continue; // 가독성 위해 else if 대신 continue 사용함
        }
        if (cmd == "pop"){
            if(s.empty())
                cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
            continue;
        }
        if (cmd == "size"){
            cout << s.size() << "\n";
            continue;
        }
        if (cmd == "empty"){
            cout << s.empty() << "\n";
            continue;
        }
        if (cmd == "top"){
            if (s.empty())
                cout << -1 << "\n";
            else
                cout << s.top() << "\n";
            continue;
        }
    }
}

