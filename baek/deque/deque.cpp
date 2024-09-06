//10866
#include <bits/stdc++.h>

int N;
std::deque<int> d;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    std::string input;
    for(int i = 0; i < N; i++) {
        std::cin >> input;
        if(input == "push_back") {
            int val;
            std::cin >> val;
            d.push_back(val);
        } else if(input == "push_front") {
            int val;
            std::cin >> val;
            d.push_front(val);
        } else if(input == "pop_front") {
            if(d.empty()) std::cout << -1 << '\n';
            else {
                std::cout << d.front() << '\n';
                d.pop_front();
            }
        } else if(input == "pop_back") {
            if(d.empty()) std::cout << -1 << '\n';
            else {
                std::cout << d.back() << '\n';
                d.pop_back();
            }
        } else if(input == "size") {
            std::cout << d.size() << '\n';
        } else if(input == "empty") {
            std::cout << d.empty() << '\n';
        } else if(input == "front") {
            if(d.empty()) std::cout << -1 << '\n';
            else {
                std::cout << d.front() << '\n';
            }
        } else {
            if(d.empty()) std::cout << -1 << '\n';
            else {
                std::cout << d.back() << '\n';
            }
        }
    }
}