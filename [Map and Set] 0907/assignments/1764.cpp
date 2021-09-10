//
// Created by Kang Minji on 2021-09-08.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, ans=0;
    string input;
    cin >> n >> m;

    // 01. 듣도 못한 사람을 set에 등록
    set<string> name; // map보다 빨라짐!(20ms)
    while (n--){
        cin >> input;
        name.insert(input);
    }

    // 02. 보도 못한 사람과 듣도 못한 사람 비교
    // vector에 듣보잡 이름 저장
    vector<string> dupName;
    while (m--){
        cin >> input;
        if (name.count(input)){
            ans++;
            dupName.push_back(input);
        }
    }
    // 03. 듣보잡 이름 사전 순으로 정렬
    sort(dupName.begin(), dupName.end());

    // 출력
    cout << ans << "\n";
    for (int i=0; i<dupName.size();i++){
        cout << dupName[i] << "\n";
    }
}