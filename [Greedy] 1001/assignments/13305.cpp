//
// Created by Kang Minji on 2021-10-07.
//

#include <iostream>
#include <vector>
const int MAX =  1000000000;
using namespace std;

vector<long long> dist;
vector<long long> cost;

long long minCost(int n){
    long long sum = 0;
    long long min_val = MAX;
    /*
     * 1) 첫 번째 도시 : 다음 도시까지 가기 위해 무조건 기름 넣어야 함
     * 2) 현재 도시의 기름값이 더 싼 경우 -> update
     * 3) 현재 도시의 기름값이 비싼 경우 -> min_val에 저장했던 기름값 사용(거기에서 충전해온다고 생각하기)
     */
    for (int i=0; i<n-1; i++){
        if (min_val > cost[i])
            min_val = cost[i];
        sum += min_val * dist[i];
    }
    return sum;
}

int main(){
    int n; // 도시의 개수

    // 입력
    cin >> n;
    dist.assign(n, 0);
    cost.assign(n, 0);
    for (int i=0; i<n-1; i++) // n 아니고 n-1
        cin >> dist[i]; // 도로의 길이
    for (int i=0; i<n; i++)
        cin >> cost[i]; // 리터당 가격

    // 연산 + 출력
    cout << minCost(n);
}
