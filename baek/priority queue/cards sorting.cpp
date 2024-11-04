//1715
#include <bits/stdc++.h>

int N;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int val;
    for(int i = 0; i < N; i++) {
        std::cin >> val;
        pq.push(val);
    }

    int ans = 0; //그리디, a+b로 만들어진 카드 뭉치 c를 d와 합칠때 비교 횟수는 (a+b)+(a+b+c)가 되므로
                 //가능한 가장 작은 카드 뭉치를 먼저 비교해야함
    while(pq.size() > 1) {
        int temp = pq.top();
        pq.pop();
        temp += pq.top();
        pq.pop();

        ans += temp;
        pq.push(temp);
    }

    std::cout << ans;
}