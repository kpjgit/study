//1781
#include <bits/stdc++.h>

int N;
std::priority_queue<int> pq;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    std::vector<std::vector<int>> v(N + 1);
    int d, c;
    for(int i = 0; i < N; i++) {
        std::cin >> d >> c;
        v[d].push_back(c);
    }

    int ans = 0;
    for(int i = N; i > 0; i--) {
        for(int c : v[i]) pq.push(c); //앞에서부터 확인할 경우 뒤에 나올 수 있는 컵라면을 많이 주는 문제를 놓칠 수 있음
                                      //따라서 가장 뒤에서 시작해서 데드라인 안쪽의 문제들을 힙에 넣고 최대를 골라야함

        if(pq.empty()) continue;
        ans += pq.top();
        pq.pop();
    }

    std::cout << ans;
}