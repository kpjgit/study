//2075
#include <bits/stdc++.h>

int N;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int val;
    for(int i = 0; i < N * N; i++) {
        std::cin >> val;
        pq.push(val);

        if(pq.size() > N) pq.pop();
    }

    std::cout << pq.top();
}