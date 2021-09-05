// 국영수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info{
  string name;
  int korean, english, math;
};

bool compare(const info &i1, const info &i2){
  if (i1.korean != i2.korean) // 국어 점수 다르다면 감소하는 순서
    return i1.korean > i2.korean;
  if (i1.english != i2.english) // 영어 점수 다르다면 증가하는 순서
    return i1.english < i2.english;
  if (i1.math != i2.math) // 수학 점수가 다르다면 감소하는 순서
    return i1.math > i2.math;
  return i1.name < i2.name; // 이름이 사전 순으로 증가하는 순서
}

int main(){
  int n;
  vector<info> student;
  
  cin >> n;
  student.assign(n, {}); // 구조체 초기화 : {}
  for (int i=0; i<n; i++){
    cin >> student[i].name >> student[i].korean >> student[i].english >> student[i].math;
  }
  /*
  for (int i=0l i<n; i++){
    string str;
    int a, b, c;
    cin >> str >> a >> b >> c;
    student[i] = {str, a, b, c};
  }*/

  sort(student.begin(), student.end(), compare);
  
  for (int i=0; i<n; i++){
    cout << student[i].name << "\n";
  }
}