//10828
#include <bits/stdc++.h>

int N;
std::string input;
std::stack<int> s;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;

    for(int i = 0; i < N; i++) {
        std::cin >> input;

        if(input == "push") {
            int val;
            std::cin >> val;
            s.push(val);
        } else if(input == "pop") {
            if(s.empty()) {
                std::cout << -1 << '\n';
            } else {
                std::cout << s.top() << '\n';
                s.pop();
            }
        } else if(input == "size") {
            std::cout << s.size() << '\n';
        } else if(input == "empty") {
            std::cout << s.empty() << '\n';
        } else {
            if(s.empty()) std::cout << -1 <<'\n';
            else std::cout << s.top() << '\n';
        }
    }
}