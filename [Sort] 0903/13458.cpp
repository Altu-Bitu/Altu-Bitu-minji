#include <iostream>
#include <vector>
using namespace std;
vector<int> A;

long long solution(int N, int B, int C){
  // main : 총감독관 관리 수, sub : 부감독관 관리 수
  long long answer = 0;
  for (int i=0; i<N; i++){
    A[i] -= B;
    answer++;
    if (A[i] > 0){
      answer += A[i]/C;
      if (A[i]%C != 0)
        answer += 1;
    }
  }
  return answer;
}

int main(){
  int N, B, C;
  cin >> N;
  for (int i=0; i<N; i++){
    int a;
    cin >> a;
    A.push_back(a);
  }
  cin >> B >> C;
  cout << solution(N, B, C);
}