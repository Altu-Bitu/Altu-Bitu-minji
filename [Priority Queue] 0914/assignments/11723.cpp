//
// Created by Kang Minji on 2021-09-15.
//

#include <iostream>
using namespace std;
int arr[21]; // 있으면 1, 없으면 0

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    string input;

    cin >> n;
    while(n--){
        cin >> input;
        if (input == "add"){
            cin >> k;
            arr[k] = 1;
        }
        else if (input == "remove"){
            cin >> k;
            arr[k] = 0;
        }
        else if (input == "check") {
            cin >> k;
            cout << arr[k] << "\n";
        }
        else if (input == "toggle"){
            cin >> k;
            if (arr[k] == 1)
                arr[k] = 0;
            else
                arr[k] = 1;
        }
        else if (input == "all")
            fill_n(arr, 21, 1); // 존재함(1)
        else if (input == "empty")
            fill_n(arr, 21, 0); // 존재하지 않음(0)

    }
}