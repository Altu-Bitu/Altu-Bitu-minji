#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arr;

// 면접 순위 체크
int solution(int n){
  // 서류 1등은 무조건 합격
  // 서류 1등의 면접 순위보다 높아야 합격
  int cnt = 1;
  int standard = arr[0].second;
  for (int i=1; i<n; i++){
    if (arr[i].second < standard){
      standard = arr[i].second;
      cnt++;
    }
  }
  return cnt;
}

int main(){
  int t, n;
  cin >> t;

  for (int i=0; i<t; i++){
    cin >> n;
    arr.assign(n, {0, 0});

    for (int j=0; j<n; j++){
      cin >> arr[j].first >> arr[j].second;
    }

    // 서류 순위대로 정렬
    sort(arr.begin(), arr.end());

    cout << solution(n) << "\n";
  }
}