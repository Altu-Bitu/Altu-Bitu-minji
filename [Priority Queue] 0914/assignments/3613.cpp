//
// Created by Kang Minji on 2021-09-15.
//

// 실패
/*
 * 예외 사항
 * 01. 시작이 _거나 대문자
 * 02. _가 연속으로 나오는 경우
 * 03. _와 대문자가 같이 나오는 경우
 * 04. 마지막이 _인 경우
 *
 * 05. c++인데 대문자 / java인데 _가 나오는 경우
 * */
#include <iostream>
using namespace std;

int main(){
    string str, ans="";
    bool isJava, isC, isError = false;
    cin >> str;

    // 예외 01. 시작이 '_'이거나 대문자인 경우 + 마지막 문자가 '_'인 경우
    if (isupper(str[0]) || str[0] == '_' || str[str.length()-1] == '_') {
        cout << "Error\n";
        return 0;
    }
    ans += str[0];

    for (int i=1; i<str.length(); i++){
        // 01. c++인 경우('_' 포함)
        if (str[i] == '_') {
            // 예외 02. java이거나 '_'이 연속으로 있는 경우
            if (isJava || str[i-1] == '_'){
                isError = true;
                break;
            }
            isC = true;
        }
        // 02. java인 경우(대문자 포함)
        else if (isupper(str[i])){
            // 예외 03. c++인 경우
            if (isC) {
                isError = true;
                break;
            }
            isJava = true;
            // 왜인지 모르겠으나 _랑 tolower이랑 같이 쓰면 같이 이상하게 나옴
            ans += '_';
            ans += tolower(str[i]);
        }
        // 03. 소문자인 경우
        else {
            if (str[i-1] == '_')
                ans += toupper(str[i]);
            else
                ans += str[i];
        }
    }

    if (isError)
        cout << "Error\n";
    else
        cout << ans;
}