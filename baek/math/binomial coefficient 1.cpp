//11050
#include <bits/stdc++.h>

int N, K;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    int ans = 1;
    for(int i = N; i > N - K; i--) ans *= i;
    for(int i = 2; i <= K; i++) ans /= i;
    std::cout << ans;
}