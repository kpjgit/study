//23326
#include <bits/stdc++.h>

int N, Q;
std::set<int> s;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> Q;
    bool temp;
    for(int i = 0; i < N; i++) {
        std::cin >> temp;
        if(temp) s.insert(i);
    }

    int cur = 0;
    int op, val;
    for(int i = 0; i < Q; i++) {
        std::cin >> op;
        if(op == 1) {
            std::cin >> val;
            val--;
            if(s.find(val) != s.end()) s.erase(val);
            else s.insert(val);
        } else if(op == 2) {
            std::cin >> val;
            cur = (cur + val) % N;
        } else {
            if(s.empty()) {
                std::cout << -1 << '\n';
                continue;
            }

            auto iter = s.lower_bound(cur);
            if(iter == s.end()) {
                std::cout << N - cur + *s.begin() << '\n';
            } else {
                std::cout << *iter - cur << '\n';
            }
        }
    }
}