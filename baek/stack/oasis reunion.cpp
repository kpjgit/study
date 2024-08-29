//3015
#include <bits/stdc++.h>

int N;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long ans = 0;
    std::cin >> N;
    int input;
    std::stack<std::pair<int, int>> s;

    for(int i = 0; i < N; i++) {
        std::cin >> input;

        int cnt = 1;
        while(!s.empty() && s.top().first <= input) {
            ans += s.top().second;
            if(s.top().first == input) cnt += s.top().second;
            s.pop();
        }

        if(!s.empty()) ans++;

        s.push({input, cnt});
    }

    std::cout << ans;
}