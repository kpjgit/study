#include <bits/stdc++.h>

bool state[65];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    int val;
    int cnt;
    int N;
    for(int num = 0; num < T; num++) {
        std::cin >> N;

        std::fill(state + 1, state + N + 1, false);
        for(int i = 1; i <= N; i++) {
            std::cin >> val;
            if(i == val) state[i] = true;
        }

        for(int i = 0; i < N * N - N; i++) std::cin >> val;

        cnt = 0;
        for(int i = N; i >= 1; i--) {
            if(state[i]) continue;
            
            cnt++;
            for(int j = i; j >= 2; j--) state[j] = !state[j];
        }

        std::cout << cnt << '\n';
    }
}