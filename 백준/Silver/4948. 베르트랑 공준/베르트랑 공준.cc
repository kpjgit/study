#include <bits/stdc++.h>

int n;

int func(int n) {
    std::vector<bool> state(2 * n + 1, true);

    state[0] = state[1] = false;
    for(int i = 2; i * i <= 2 * n; i++) {
        if(state[i] == false) continue;

        for(int j = i * i; j <= 2 * n; j += i) state[j] = false;
    }

    int ans = 0;
    for(int i = n + 1; i <= 2 * n; i++) if(state[i] == true) ans++;
    return ans;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while(true) {
        std::cin >> n;
        if(n == 0) break;

        std::cout << func(n) << '\n';
    }
}