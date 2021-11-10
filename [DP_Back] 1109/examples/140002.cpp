//
// Created by Kang Minji on 2021-11-09.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<int> back(int x, vector<int> &path){
    vector<int> result(0);
    while(x!=-1){
        result.push_back(x);
        x = path[x]; // 다음 경로
    }
    return result;
}

ci lis(int n, vector<int> &arr, vector<int> &path){
    vector<int> dp(n+1, 1);
    ci ans = {1, 0}; // 최장 길이, 마지막 원소의 인덱스

    for (int i=1; i<n; i++){
        int index = -1; // 경로 저장할 변수
        for (int j=0; j<i;j++){
            if (arr[i] > arr[j] && dp[i] < dp[j]+1) { // 증가하는 관계, 가장 큰 dp[j]+1
                dp[i] = dp[j]+1;
                index = j;
            }
        }
        path[i] = index;
        if (ans.first < dp[i]) // 최장 길이 + 마지막 원소의 인덱스
            ans = {dp[i], i};

    }
    return ans;
}

int main(){
    int n;

    cin >> n;
    vector<int> arr(n);
    vector<int> path(n, -1); // 경로 저장 배열
    for (int i=0; i<n; i++)
        cin >> arr[i];

    ci ans = lis(n, arr, path);
    vector<int> result = back(ans.second, path);

    cout << ans.first << "\n";
    for (int i=result.size() -1 ; i>=0; i--)
        cout << arr[result[i]] << "\n";
}