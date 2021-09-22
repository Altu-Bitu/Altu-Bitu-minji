//
// Created by Kang Minji on 2021-09-23.
//

#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if (b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int main(){
    int t, n, num;
    cin >> t;

    while(t--){
        cin >> n;
        vector<int> v;

        // 벡터에 숫자 입력
        for (int i=0; i<n; i++){
            cin >> num;
            v.push_back(num);
        }

        /* n개의 수를 2개씩 짝지어 만드는 경우의 수 = n*(n+1)/2
         * n*(n+1)/2 개의 최대공약수 범위 : 1~1000000
         * -> (100*99/2)*1000000
         * -> long long 사용해야 함
         * */
        long long sum = 0;

        // 모든 쌍의 gcd 구하기
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                sum += gcd(max(v[i], v[j]), min(v[i], v[j]));
            }
        }
        cout << sum << "\n";
    }
}