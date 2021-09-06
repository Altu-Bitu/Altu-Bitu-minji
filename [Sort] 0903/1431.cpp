// 1431번 : 시리얼 번호
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> arr;

// 02-1. 문자열에서 숫자인 자리만 합해서 리턴
int findSum(string str){
    int sum = 0;
    for (int i=0; i<str.length(); i++){
        if (isdigit(str[i]) != 0)
            sum += str[i] - '0';
    }
    return sum;
}

bool compare(const string &a, const string &b){
  // 01. 길이가 다르면 짧은 것 우선
  if (a.length() != b.length())
    return a.length() < b.length();
  
  // 02. 길이가 같으면 자리수 합 작은 것이 우선
  int a_sum = findSum(a);
  int b_sum = findSum(b);
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