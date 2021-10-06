//
// Created by Kang Minji on 2021-10-07.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cake_mult; // 10의 배수인 케이크
vector<int> cake; // 10 이상인 케이크

/* 1) 길이가 10보다 큰 경우만 자르기
 * 2) 길이-10이 더 큰 케이크 먼저 자르기
 * -> 10의 배수인 경우가 케이크 개수 많이 나옴
 *
 * [우선순위]
 * 10의 배수 순서대로 sort & 자르기
 * 10 이상인 케이크 순서대로 sort & 자르기
 */
int makeCake(int m, int ans){
    int cut = 0;

    for (int i=0; i<cake_mult.size(); i++){
        while(cake_mult[i] >= 10){
            if (cake_mult[i] == 10) {
                ans++;
                break;
            }
            if (cut == m)
                return ans;
            cake_mult[i] -= 10;
            ans++;
            cut++;
        }
    }
    return ans;
}

int main(){
    int n, m, tmp;
    int ans = 0;

    // 입력
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        if (tmp == 10)  // 1) 10인 경우는 바로 ans에 추가
            ans++;
        else if (tmp%10 == 0) // 2) 10의 배수인 경우
            cake_mult.push_back(tmp);
        else // 3) 10 이상인 경우
            cake.push_back(tmp);
    }

    // 연산
    sort(cake_mult.begin(), cake_mult.end());
    sort(cake.begin(), cake.end());

    // (2) 뒤에 (3) 추가한다
    for (int i=0; i<cake.size(); i++){
        cake_mult.push_back(cake[i]);
    }

    cout << makeCake(m, ans);

}