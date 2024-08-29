//10773
#include <bits/stdc++.h>

int K;
std::stack<int> s;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> K;
    int input;
    for(int i = 0; i < K; i++) {
        std::cin >> input;
        if(input == 0) s.pop();
        else s.push(input);
    }

    int ans = 0;
    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }

    std::cout << ans;
}