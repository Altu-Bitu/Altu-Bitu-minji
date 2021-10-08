//
// Created by Kang Minji on 2021-09-17.
//
// substr : [pos, pos+count)

#include <iostream>
using namespace std;

int gcd(int n, int m){
    if (m == 0)
        return n;
    return gcd(m, n%m);
}

int main(){
    int n, m, idx;
    string s;
    cin >> s;

    idx = s.find(":");
    n = stoi(s.substr(0, idx));
    m = stoi(s.substr(idx+1, s.length()));

    int g = gcd(max(n, m), min(n, m));
    cout << n/g << ":" << m/g;
}