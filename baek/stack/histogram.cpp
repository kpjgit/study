//6549
#include <bits/stdc++.h>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while(true) {
        std::cin >> n;
        if(n == 0) break;
        long long ans = 0;
        std::stack<std::pair<int, int>> s;
        for(int i = 0; i < n; i++) {
            int input;
            std::cin >> input;
            int idx = i;

            while(!s.empty() && s.top().first >= input) {
                ans = std::max(ans, 1LL * (i - s.top().second) * s.top().first);
                idx = s.top().second;
                s.pop();
            }
            s.push({input, idx});
        }

        while(!s.empty()) {
            ans = std::max(ans, 1LL * (n - s.top().second) * s.top().first);
            s.pop();
        } 
        std::cout << ans << '\n';
    }
}