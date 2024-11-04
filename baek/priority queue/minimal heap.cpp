//1927
#include <bits/stdc++.h>

int N;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int x;
    for(int i = 0; i < N; i++) {
        std::cin >> x;
        if(x == 0) {
            if(pq.empty()) {
                std::cout << 0 << '\n';
                continue;
            }

            std::cout << pq.top() << '\n';
            pq.pop();
        } else pq.push(x);
    }
}