// 11399번 : ATM
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> times;

int solution(int n){
  int answer = 0, sum=0;
  for (int i=0; i<n; i++){
    for (int j=0; j<=i; j++){
      sum += times[j];
    }
    answer+=sum;
    sum = 0;
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