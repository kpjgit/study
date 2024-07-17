//1978
#include <bits/stdc++.h>

int n;


bool is_prime(int x) {
    if(x == 1) return 0;

    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return 0;
    }

    return 1;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ans = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        if(is_prime(temp)) ans++;
    }

    std::cout << ans;
}