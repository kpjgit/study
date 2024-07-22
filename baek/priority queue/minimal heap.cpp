//1927
#include <bits/stdc++.h>

int n;
std::priority_queue<int, std::vector<int>, std::greater<int>> q;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        if(input == 0) {
            if(q.empty()) {
                std::cout << 0 << '\n';
            } else {
                std::cout << q.top() << '\n';
                q.pop();
            }
        } else {
            q.push(input);
        }
    }
}