//11003
#include <bits/stdc++.h>

int N, L;
std::deque<std::pair<int, int>> d;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> L;

    int val;
    for(int i = 0; i < N; i++) {
        std::cin >> val;

        while(!d.empty() && d.back().second >= val) {
            d.pop_back();
        }

        d.push_back({i, val});

        if (d.front().first <= i - L) {
            d.pop_front();
        }

        std::cout << d.front().second << ' ';
    }
}