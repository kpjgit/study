//11286
#include <bits/stdc++.h>

int N;

struct cmp {
    bool operator() (int a, int b) {
        if(std::abs(a) != std::abs(b)) return std::abs(a) > std::abs(b);
        return a > 0 && b < 0; //a==b 일때 false 반환해야함
    }
};

std::priority_queue<int, std::vector<int>, cmp> pq;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int val;
    for(int i = 0; i < N; i++) {
        std::cin >> val;

        if(val == 0) {
            if(pq.empty()) {
                std::cout << 0 << '\n';
                continue;
            }

            std::cout << pq.top() << '\n';
            pq.pop();
        } else pq.push(val);
    }
}