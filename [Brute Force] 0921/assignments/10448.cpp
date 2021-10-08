//
// Created by Kang Minji on 2021-09-27.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeTriangle(vector<int> v){
    int num = 0;
    for (int i=1; num<1000; i++){
        num += i;
        v.push_back(num);
    }
    return v;
}

int main(){
    int n, k, ans = 0;

    // 삼각수 입력하기
    vector<int> v;
    v = makeTriangle(v);

    // 입력
    cin >> n;
    while (n--){
        cin >> k;
        // 연산 + 출력
        for (int i=0; i<v.size(); i++){
            for (int j=0; j<v.size(); j++){
                for (int p=0; p<v.size(); p++){
                    if ((v[i] + v[j] + v[p]) == k)
                        ans = 1;
                }
            }
        }
        cout << ans << "\n";
        ans = 0;
    }
}