//
// Created by Kang Minji on 2021-09-08.
//

#include <iostream>
#include <algorithm> // reverse
using namespace std;

int main(){
    // long long 자료형 길이 초과 -> string으로 받기
    string a, b;
    cin >> a >> b;

    int lenA = a.length();
    int lenB = b.length();

    // 01. 무조건 A 자릿수 크게 만들기
    if (lenB > lenA) {
        swap(a, b);
        swap(lenA, lenB);
    }

    // 02. 자릿수 다르면 맞춰주기
    // ex) 1234, 0032
    string tmp = "";
    if (lenA != lenB){
       for (int i=0; i<(lenA-lenB); i++)
           tmp += "0";
    }
    b = tmp+b;

    // 03. 뒷자리부터 하나씩 나눠서 answer에 추가
    string ans = "";
    int carry = 0; // 올림
    int x, y, digit; // 자리수
    for (int i=lenA-1; i>=0; i--){
        x = a[i] - '0';
        y = b[i] - '0';
        digit = x + y;
        if (carry == 1) {
            digit++;
            carry = 0;
        }
        if (digit > 9) // 반올림하는 경우
            carry = 1;
        ans += to_string(digit%10);
    }

    // 추가되는 한 자리 ex) 23+95 = (1)18
    if (carry == 1)
        ans += "1";

    reverse(ans.begin(), ans.end());

    cout << ans;

}
