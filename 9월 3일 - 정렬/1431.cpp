// 1431번 : 시리얼 번호
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> arr;

bool compare(const string &a, const string &b){
  // 01. 길이가 다르면 짧은 것 우선
  if (a.length() != b.length())
    return a.length() < b.length();
  
  // 02. 길이가 같으면 자리수 합 작은 것이 우선
  int a_sum = 0, b_sum = 0;
  for (int i=0; i<a.length(); i++){
    if (a[i] >= '0' && a[i] <= '9')
      a_sum += a[i] - '0';
    if (b[i] >= '0' && b[i] <= '9')
      b_sum += b[i] - '0';
  }
  if (a_sum != b_sum)
    return a_sum < b_sum;

  // 03. 사전순으로 비교
  return a < b;
}

int main(){
  int n;
  cin >> n;
  arr.assign(n, "");
  
  for (int i=0; i<n; i++){
    cin >> arr[i];
  }
  
  sort(arr.begin(), arr.end(), compare);
  
  for (int i=0; i<n; i++){
    cout << arr[i] << "\n";
  }
}