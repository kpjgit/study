//1929
#include <bits/stdc++.h>

int M, N;

std::vector<int> func(int n) {
    std::vector<int> primes;
    std::vector<bool> v(n + 1, true);
    v[1] = false;

    for(int i = 2; i * i <= n; i++) {
        if(v[i] == false) continue;
        
        for(int j = i * i; j <= n; j += i) v[j] = false;
    }

    for(int i = 2; i <= n; i++) if(v[i]) primes.push_back(i);

    return std::move(primes);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> M >> N;
    std::vector<int> primes = func(N);

    for(int i : primes) {
        if(i >= M) std::cout << i << '\n';
    }
}