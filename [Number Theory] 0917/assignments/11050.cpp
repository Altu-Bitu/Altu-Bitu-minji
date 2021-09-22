//
// Created by Kang Minji on 2021-09-22.
//

#include <iostream>
using namespace std;

int factorial(int n){
    if (n == 1 || n == 0)
        return 1;
    return n*factorial(n-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    cout << factorial(n)/(factorial(n-k)* factorial(k));
}