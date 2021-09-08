//
// Created by Kang Minji on 2021-09-08.
//

#include <iostream>
#include <map>
using namespace std;

int main(){
    int t, n, ans=1;
    string name, type;
    cin >> t;

    while(t--){
        cin >> n;
        map<string, int> cloth;
        while (n--){ // map에 저장
            cin >> name >> type;
            cloth[type]++;
        }
        for (auto & iter : cloth){ // 옷 입는 가짓수
            ans *= iter.second + 1; // 종류별 옷 수 + 선택하지 않는 경우 1가지
            // ex) head : a, b, ∅
            // ex) eye : c, ∅
        }
        ans--; // {∅ , ∅} 인 경우 제외
        cout << ans << "\n";
        ans = 1;
    }
}