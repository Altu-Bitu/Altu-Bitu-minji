#include <iostream>
#include <queue>
using namespace std;

int main(){
    // 절댓값과 원래 값 pair로 저장(오름차순)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        // 01. x가 0이 아니라면 큐에 x 추가
        if (x!=0)
            pq.push({abs(x), x});
            // 02. x가 0이라면 절댓값이 가장 작은 값 출력 후 큐에서 제거
        else{
            if (pq.empty())
                cout << "0" << "\n";
            else {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
    }
}