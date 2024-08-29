//6198
#include <bits/stdc++.h>

int N;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long ans = 0;
    std::cin >> N;
    long long input;
    std::stack<long long> s;

    for(int i = 0; i < N; i++) {
        std::cin >> input;
        
        while(!s.empty() && s.top() <= input) {
            s.pop();
        }
        ans += s.size();

        s.push(input);
    }

    std::cout << ans;
}