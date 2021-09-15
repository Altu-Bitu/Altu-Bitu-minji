//
// Created by Kang Minji on 2021-09-14.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<string, int> word; // 단어의 빈도수 저장
vector<string> voca; // 단어장

bool compare(const string &a, const string &b){
    // 01. 자주 나오는 단어일수록 앞에 배치
    if (word[a] != word[b])
        return word[a] > word[b];
    // 02. 해당 단어의 길이가 길수록 앞에 배치
    if (a.length() != b.length())
        return a.length() > b.length();
    // 03. 알파벳 사전 순으로 앞에 배치
    return a < b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string input;

    cin >> n >> m;
    while(n--){
        cin >> input;
        // 단어의 길이가 m보다 작고, map에 없는 경우
        if (input.length() >= m && word[input] == 0) {
           voca.push_back(input);
        }
        word[input]++;
    }

    sort(voca.begin(), voca.end(), compare);

    for(int i=0; i<voca.size(); i++)
        cout << voca[i] << "\n";
}