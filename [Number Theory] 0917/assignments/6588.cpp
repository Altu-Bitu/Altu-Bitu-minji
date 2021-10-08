//
// Created by Kang Minji on 2021-09-23.
//

#include <iostream>
#include <vector>
#define SIZE 1000000
using namespace std;

vector<bool> makePrime(){
    vector<bool> is_prime(SIZE+1, true);
    is_prime[0] = is_prime[1] = false;

    // 01. 에라토스테네스의 체
    for (int i=2; i*i<=SIZE; i++){
        if (is_prime[i]) {
            for (int j = i * i; j <= SIZE; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    vector<bool> is_prime = makePrime();
    while (true){
        cin >> num;
        if (num == 0)
            break;

        bool flag = false;
        // 02. 골드바흐의 수 구하기
        // 연산 단축 -> num/2까지 연산 + i 2씩 증가
        for (int i=3; i<=num/2; i+=2){ // i*i 하면 안 됨
            if (is_prime[i] && is_prime[num-i]) {
                flag = true;
                cout << num << " = " << i << " + " << num-i << "\n";
                break;
            }
        }
        if (!flag)
            cout << "Goldbach's conjecture is wrong\n";
    }
}