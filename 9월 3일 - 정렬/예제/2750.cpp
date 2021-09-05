#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 정렬할 배열
vector<int> arr;

// 버블 정렬
void bubbleSort(int n){
    int cnt = 0;
    for (int i=0; i<n; i++){
        bool flag = true;
    // 0 ~ n-1까지 정렬 -> 0 ~ n-2까지 정렬 -> ... -> 0~1까지 정렬
        for (int j=1; j<n-i; j++){
          if (arr[j-1] > arr[j]){
            flag = false;
            swap(arr[j], arr[j-1]);
         }
        }
        cnt++;
        if (flag){
            break;
        }
    }
    cout << "Count : " << cnt << "\n";
}

int main() {
  int n;

  cin >> n;
  arr.assign(n, 0); // 크기 할당 및 초기화

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  // 연산
  bubbleSort(n);
}
