//
// Created by Kang Minji on 2021-09-09.
//

// 좌표 압축 : 입력받은 좌표값을 오름차순으로 정렬했을 때의 순서 표시(중복은 제외)
// 즉 해당 값보다 작은 값들의 개수
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// 성공은 했지만 속도 너무 느림(제한 시간과 동일)
 int main(){
    int n, x;
    cin >> n;
    map<int, int> rank; // key : 숫자, value : 좌표 압축값
    vector<int> num, tmp;

    while(n--){
        cin >> x;
        num.push_back(x);
    }

    tmp = num;
    sort(tmp.begin(), tmp.end());
    int idx = 1;
    for (int i=0; i<tmp.size(); i++) {
        if (!rank[tmp[i]])
            rank[tmp[i]] = idx++;
    }

    for (int i=0; i<num.size(); i++){
        cout << rank[num[i]] - 1 << " ";;
    }
}

// 시간초과
int main(){
    ios::sync_with_stdio(false);
    cin.tie(false);

    int n, x;
    cin >> n;
    map<int, int> rank; // key : 숫자, value : 좌표 압축값
    vector<int> num;

    while(n--){
        cin >> x;
        rank[x]; // map에 key 넣어줌(자동 정렬)
        num.push_back(x);
    }

    int i=0; // 좌표 압축값
    for (auto & iter : rank) { // & 붙여줘야 함
        iter.second = i++; // 압축값 하나씩 증가
    }

    for (int i=0; i<num.size(); i++){
        cout << rank[num[i]] << " ";;
    }
}