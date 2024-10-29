//1644
#include <bits/stdc++.h>

int N;

std::vector<int> func(int n) {
    std::vector<int> primes;
    std::vector<bool> state(n + 1, true);
    state[0] = state[1] = false;

    for(int i = 2; i * i <= n; i++) {
        if(state[i] == false) continue;

        for(int j = i * i; j <= n; j += i) state[j] = false;
    }

    for(int i = 2; i <= n; i++) if(state[i]) primes.push_back(i);

    return primes;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    if(N == 1) {
        std::cout << 0;
        return 0;
    }
    std::vector<int> primes = func(N);

    int st = 0;
    int en = 0;
    int ans = 0;
    int sum = primes[0];
    while(st < primes.size() && en < primes.size()) {
        if(sum < N) {
            en++;
            sum += primes[en];
        } else {
            if(sum == N) ans++;
            sum -= primes[st];
            st++;
        }
    }

    std::cout << ans;
}