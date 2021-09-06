// 11651번 좌표 정렬하기 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> dots;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
  if (a.second != b.second)
    return a.second < b.second;
  return a.first < b.first;
}


int main(){
  int n;
  cin >> n;
  dots.assign(n, {0, 0});

  for (int i=0; i<n; i++){
    cin >> dots[i].first >> dots[i].second;
  }

  sort(dots.begin(), dots.end(), compare);
  
  for (int i=0; i<n; i++){
    cout << dots[i].first << " " << dots[i].second << "\n";
  }
}