//4948
#include <bits/stdc++.h>

int n;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int mx = 2 * 123456;
    std::vector<bool> state(mx + 1, true);
    state[0] = state[1] = false;
    for(int i = 2; i * i <= mx; i++) {
        if(state[i] == false) continue;

        for(int j = i * i; j <= mx; j += i) state[j] = false;
    }

    while(true) {
        std::cin >> n;
        if(n == 0) break;

        int ans = 0;
        for(int i = n + 1; i <= 2 * n; i++) if(state[i] == true) ans++;
        std::cout << ans << '\n';
    }
}