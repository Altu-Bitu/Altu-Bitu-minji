// 11399번 : ATM
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> times;

int solution(int n){
  int answer = 0;
  for (int i=0; i<n; i++){
    answer += (times[i]*(n-i)); // 시간 복잡도 줄이기
  }
  return answer;
}


int main(){
  int n;

  cin >> n;
  times.assign(n, 0);

  for (int i=0; i<n; i++){
    cin >> times[i];
  }

  sort(times.begin(), times.end());

  cout << solution(n);
}