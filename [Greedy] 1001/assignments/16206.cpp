//
// Created by Kang Minji on 2021-10-07.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cake; // 10 이상인 케이크

/* 1) 길이가 10보다 큰 경우만 자르기
 * 2) 길이-10이 더 큰 케이크 먼저 자르기
 * -> 10의 배수인 경우가 케이크 개수 많이 나옴
 *
 * [우선순위]
 * 10의 배수 순서대로 sort & 자르기
 * 10 이상인 케이크 순서대로 sort & 자르기
 */

bool compare(const int &a, const int &b){
    if (a%10 == 0 && b%10 == 0) // 둘 다 10의 배수인 경우
        return a < b; // 길이가 짧은 것부터 리턴
    return a%10 == 0; // 10의 배수인 것 먼저 리턴
}

int makeCake(int m, int ans){
    int cut = 0;

    for (int i=0; i<cake.size(); i++){
        while(cake[i] >= 10){
            if (cake[i] == 10) {
                ans++;
                break;
            }
            if (cut == m)
                return ans;
            cake[i] -= 10;
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
        else // 2) 나머지는 일단 다 합친다
            cake.push_back(tmp);
    }

    // 연산
    sort(cake.begin(), cake.end(), compare);

    cout << makeCake(m, ans);

}