//
// Created by Kang Minji on 2021-09-15.
//

/*
 * 예외 사항
 * 01. C++
 *  1) '_'로 시작하거나 끝나는 경우
 *  2) '__'가 연속해서 등장하는 경우
 *  3) 대문자가 나오는 경우
 * 02. Java
 *  1) 대문자로 시작하는 경우
 *  2) '_'가 등장하는 경우
 * */

#include <iostream>
using namespace std;

bool isCpp(string str){ // c++ 형식인가?
    for (int i=0; i<str.size(); i++){
        // 대문자가 나오면 안 됨
        if (isupper(str[i]))
            return false;
        // 첫글자나 마지막 글자가 '_' 이거나 '_' 이 연속으로 나오는 경우
        if (str[i] == '_' && (i==0 || i==str.size() - 1 || str[i-1] == '_'))
            return false;
    }
    return true;
}

bool isJava(string str){ // java 형식인가?
    // 첫 글자가 소문자이고 '_'가 없으면 true 반환
    return !isupper(str[0]) && str.find('_')==string::npos;
}

string toCpp(string str){ // java -> c++
    string result;
    for (int i=0; i<str.size(); i++){
        if (isupper(str[i])) // 만약 대문자라면 앞에 '_' 넣어주기
            result += '_';
        result += tolower(str[i]); // 소문자로 바꿔서 넣기
    }
    return result;
}

string toJava(string str){ // c++ -> java
    string result;
    for (int i=0; i<str.size(); i++){
        if (str[i] == '_'){ // '_' 다음 문자를 대문자로 바꿔서 넣어주기
            result += toupper(str[i+1]);
            i++;
            continue;
        }
        result += str[i]; // 다른 문자는 그냥 삽입
    }
    return result;
}

int main() {
    string str;
    cin >> str;

    bool is_cpp = isCpp(str);
    bool is_java = isJava(str);

    // 01. 두 형식에 부합하는 경우(ex. name)
    if (is_cpp && is_java)
        cout << str;
    // 02. c++이라면 java로 바꿔서 출력
    else if (is_cpp)
        cout << toJava(str);
    // 03. java이면 c++로 바꿔서 출력
    else if (is_java)
        cout << toCpp(str);
    // 04. 둘 다 아니라면 에러 발생
    else
        cout << "Error!";
}

//int main(){
//    string str, ans="";
//    bool isJava, isC, isError = false;
//    cin >> str;
//
//    // 예외 01. 시작이 '_'이거나 대문자인 경우 + 마지막 문자가 '_'인 경우
//    if (isupper(str[0]) || str[0] == '_' || str[str.length()-1] == '_') {
//        cout << "Error\n";
//        return 0;
//    }
//    ans += str[0];
//
//    for (int i=1; i<str.length(); i++){
//        // 01. c++인 경우('_' 포함)
//        if (str[i] == '_') {
//            // 예외 02. java이거나 '_'이 연속으로 있는 경우
//            if (isJava || str[i-1] == '_'){
//                isError = true;
//                break;
//            }
//            isC = true;
//        }
//            // 02. java인 경우(대문자 포함)
//        else if (isupper(str[i])){
//            // 예외 03. c++인 경우
//            if (isC) {
//                isError = true;
//                break;
//            }
//            isJava = true;
//            // 왜인지 모르겠으나 _랑 tolower이랑 같이 쓰면 같이 이상하게 나옴
//            ans += '_';
//            ans += tolower(str[i]);
//        }
//            // 03. 소문자인 경우
//        else {
//            if (str[i-1] == '_')
//                ans += toupper(str[i]);
//            else
//                ans += str[i];
//        }
//    }
//
//    if (isError)
//        cout << "Error\n";
//    else
//        cout << ans;
//}