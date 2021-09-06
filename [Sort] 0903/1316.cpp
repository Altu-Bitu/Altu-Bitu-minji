// 그룹 단어 체커
#include <iostream>
using namespace std;

char alphabet[26]; // char로 자료형 수정
int cnt = 0;

void checker(string word){
  fill_n(alphabet, 26, 0);
  alphabet[word[0] - 'a'] = 1; // ascii 코드 대신 'a'로 작성하기!

  for (int i=1; i<word.length(); i++){
    int idx = word[i] - 'a';
    // 그룹 단어가 아닌 경우
    if (word[i-1] != word[i] && alphabet[idx] != 0)
      return;
    alphabet[idx]++;
  }
  cnt++;
}

int main(){
  int n;
  string word;
  cin >> n;
  for (int i=0; i<n; i++){
    cin >> word;
    checker(word);
  }
  cout << cnt;
}