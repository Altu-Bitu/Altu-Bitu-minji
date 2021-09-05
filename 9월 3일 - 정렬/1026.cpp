// 1026번 : 보물
// 01. 문제 의도 고려 X
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
vector<int> b;

int solution(int n){
  int sum = 0;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<>());
  for (int i=0; i<n; i++){
    sum += a[i]*b[i];
  }
  return sum;
}


int main(){
  int n;
  cin >> n;

  a.assign(n, 0);
  b.assign(n, 0);
  for (int i=0; i<n; i++){
    cin >> a[i];
  }
  
  for (int i=0; i<n; i++){
    cin >> b[i];
  }

  cout << solution(n);
}
*/

// 02. 문제 의도 고려 O
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
vector<int> b;

int solution(int n){
  int sum = 0, idx = -1;
  sort(a.begin(), a.end());
  for (int i=0; i<n; i++){
    int max = -1;
    for (int j=0; j<n-i; j++){
      if (max < b[j]){
        max = b[j];
        idx = j;
      }
    }
    sum += a[i]*max;
    b.erase(b.begin()+idx);
  }

  return sum;
}


int main(){
  int n;
  cin >> n;

  a.assign(n, 0);
  b.assign(n, 0);
  for (int i=0; i<n; i++){
    cin >> a[i];
  }
  
  for (int i=0; i<n; i++){
    cin >> b[i];
  }

  cout << solution(n);
}