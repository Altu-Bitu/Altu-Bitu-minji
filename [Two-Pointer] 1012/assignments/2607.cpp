//
// Created by Kang Minji on 2021-11-01.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int cmpWord(map<char, int> std_cnt, map<char, int> word_cnt, int len1, int len2){

    // 04. 기준 단어와 비교할 단어 차이 count
    int cnt = 0;
    for (int i='A'; i<'Z'; i++){
        cnt += abs(std_cnt[i] - word_cnt[i]);
    }

    // 1) 조건1 : 기준 문자에서 하나만 빼거나 더하면 현재 문자 만들 수 있음
    // 2) 조건2 : 기준 문자에서 하나만 바꾸면 현재 문자 만들 수 있음(ex std_cnt[i] - word_cnt[i] = 2 -> i 문자만 바꿔준다)
    if (cnt < 2 || (cnt == 2 && len1 == len2))
        return true;
    return false;


}

int main(){
    int n;
    int cnt = 0;

    // 입력
    cin >> n;
    vector<string> words(n);
    for (int i=0; i<n; i++)
        cin >> words[i];

    // 연산
    // 1) 기준 단어 알파벳 담기
    map<char, int> std_cnt; // 기준 단어의 알파벳 갯수 세어줌
    for (int i=0; i<words[0].length(); i++)
        std_cnt[words[0][i]]++;

    // 2) 다른 단어들과 비교
    for (int i=1; i<n; i++) {
        int len1 = words[0].length();
        int len2 = words[i].length();
        // 01. 길이 차이가 2 이상이면 비슷한 단어 아님
        if (abs(len1-len2) > 1 )
            continue;

        map<char, int> word_cnt; // 비교할 단어의 알파벳 갯수 세어줌

        // 02. 비교할 단어의 알파벳 종류/갯수 담기
        for (int j=0; j<words[i].length(); j++)
            word_cnt[words[i][j]]++;

        // 03. 기준 단어와 비슷한 단어인지 확인
        cnt += cmpWord(std_cnt, word_cnt, len1, len2);
    }

    // 출력
    cout << cnt << "\n";
}
