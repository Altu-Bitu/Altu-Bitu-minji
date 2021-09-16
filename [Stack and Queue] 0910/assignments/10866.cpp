//
// Created by Kang Minji on 2021-09-13.
//

#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n, k;
    string input;
    deque<int> q;
    cin >> n;

    while(n--){
        cin >> input;

        if (input == "push_front"){
            cin >> k;
            q.push_front(k);
            continue;
        }
        if (input == "push_back"){
            cin >> k;
            q.push_back(k);
            continue;
        }
        if (input == "pop_front"){
            if (q.empty())
                cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop_front();
            }
            continue;
        }
        if (input == "pop_back"){
            if (q.empty())
                cout << -1 << "\n";
            else {
                cout << q.back() << "\n";
                q.pop_back();
            }
            continue;
        }
        if (input == "size"){
            cout << q.size() << "\n";
            continue;
        }
        if (input == "empty"){
            if (q.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
            continue;
        }
        if (input == "front"){
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
            continue;
        }
        if (input == "back"){
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
            continue;
        }

    }
}
