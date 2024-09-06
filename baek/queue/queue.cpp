//10845
#include <bits/stdc++.h>

int N;
std::queue<int> q;

int main(void) {
    std::ios::sync_with_stdio(false);\
    std::cin.tie(nullptr);

    std::cin >> N;
    std::string input;

    for(int i = 0; i < N; i++) {
        std::cin >> input;
        if(input == "push") {
            int val;
            std::cin >> val;
            q.push(val);
        } else if(input == "pop") {
            if(q.empty()) std::cout << -1 << '\n';
            else {
                std::cout << q.front() << '\n';
                q.pop();
            }
        } else if(input == "size") {
            std::cout << q.size() << '\n';
        } else if(input == "empty") {
            std::cout << q.empty() << '\n';
        } else if(input == "front") {
            if(q.empty()) std::cout << -1 << '\n';
            else {
                std::cout << q.front() << '\n';
            }
        } else {
            if(q.empty()) std::cout << -1 << '\n';
            else {
                std::cout << q.back() << '\n';
            }
        }
    }
} 