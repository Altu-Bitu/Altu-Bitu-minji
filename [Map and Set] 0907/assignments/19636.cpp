//
// Created by Kang Minji on 2021-09-08.
//

/* 다이어트 전 체중 : w
 * 일일 에너지 섭취량(=기초 대사량) : basic
 * 일일 활동 대사량 : a
 *
 * 다이어트 기간
 * 일일 에너지 섭취량 : d_input
 * 일일 활동 대사량 : d_output
 *
 * w += d_input - (basic+d_output)
 *
 */

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int w, basic, t, day, d_input, d_output;

    // 입력
    cin >> w >> basic >> t;
    cin >> day >> d_input >> d_output;

    int w1 = w;
    int w2 = w;

    // 일일 기초대사량
    int basic2 = basic;

    for (int i=0; i<day; i++){
        w1 += d_input - (basic + d_output);
        w2 += d_input - (basic2 + d_output);
        // 기초대사량 변화 : w2에만 반영됨, 체중 변화 다음에 발생
        // floor 함수 사용에서 (double) 2.0을 사용하지 않았더니 백준에서 통과가 되지 않았음
        // 반환형이 double이라 앞에 (int)를 붙이면 될 줄 알았는데 이것도 안 됨.
        if (abs(d_input - (basic2 + d_output)) > t)
            basic2 += (double)floor((d_input - (basic2 + d_output))/2.0);
    }

    // 출력 01. 일일 기초대사량의 변화 반영 X
    if (w1 <= 0)
        cout << "Danger Diet\n";
    else
        cout << w1 << " " << basic << "\n";

    // 출력 02. 일일 기초대사량의 변화 반영 O
    if (w2 <= 0 || basic2 <= 0)
        cout << "Danger Diet\n";
    else{
        cout << w2 << " " << basic2 << " ";
        if (basic - basic2 > 0) // 체중이 아니라 일일 기초대사량으로 비교해야 함
            cout << "YOYO";
        else
            cout << "NO";
    }
}
