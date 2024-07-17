//1929
#include <bits/stdc++.h>

int m, n;

std::vector<int> find_primes(int n) {
    std::vector<int> primes;
    std::vector<bool> state(n + 1, true);
    state[1] = false;

    for(int i = 2; i * i <= n; i++) {
        if(state[i] == false) continue;
        for(int j = i * i; j <= n; j += i) state[j] = false;
    }

    for(int i = 2; i <= n; i++) {
        if(state[i] == true) primes.push_back(i);
    }

    return primes;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> m >> n;

    for(auto ans: find_primes(n)) {
        if(ans >= m) std::cout << ans << '\n';
    }
}